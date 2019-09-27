Module = {};
var canv = document.getElementById("canvas");
Module.canvas = canv;

Module.onRuntimeInitialized = () => {
  store.subscribe(() => {
    console.log("hello world");
    let sceneGraph = JSON.stringify(store.getState().sceneGraph);
    var encodedSceneGraph = new TextEncoder("utf-8").encode(sceneGraph);
    const numBytes =
      encodedSceneGraph.length * encodedSceneGraph.BYTES_PER_ELEMENT;
    const dataPtr = Module._malloc(numBytes);
    const dataOnHeap = new Uint8Array(Module.HEAPU8.buffer, dataPtr, numBytes);
    dataOnHeap.set(encodedSceneGraph);

    Module._update_scene_graph(dataOnHeap.byteOffset);

    Module._free(dataPtr);
  });
};
