import { generateUUID } from "../utils/generateUUID.js";

export default {
  sceneGraph: {
    world: {
      ID: "WORLD",
      modelFilename: "",
      scale: [1, 1, 1],
      rotation: [0, 0, 0],
      translation: [0, 0, 0],
      children: [
        {
          ID: generateUUID(),
          modelFilename: "teapot.obj",
          scale: [0.5, 0.5, 0.5],
          rotation: [0, 0, 0],
          translation: [0, 0, 0],
          children: []
        },
        {
          ID: generateUUID(),
          modelFilename: "bunny.obj",
          scale: [10, 10, 10],
          rotation: [0, 0, 0],
          translation: [2.5, 2.5, 2.5],
          children: []
        }
      ]
    }
  }
};
