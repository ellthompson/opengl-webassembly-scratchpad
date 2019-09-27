import {
  UPDATE_MODEL_SCALE,
  UPDATE_MODEL_ROTATION,
  UPDATE_MODEL_TRANSLATION
} from "../constants/actionTypes";
import objectAssign from "object-assign";
import initialState from "./initialState";

function updateModelScaleInGraph(model, ID, value, index) {
  if (ID == model.ID) {
    model.scale[index] = value;
  } else {
    for (var i = 0; i < model.children.length; i++) {
      model.children[i] = updateModelScaleInGraph(
        model.children[i],
        ID,
        value,
        index
      );
    }
  }
  return model;
}

function updateModelRotationInGraph(model, ID, value, index) {
  if (ID == model.ID) {
    model.rotation[index] = value;
  } else {
    for (var i = 0; i < model.children.length; i++) {
      model.children[i] = updateModelRotationInGraph(
        model.children[i],
        ID,
        value,
        index
      );
    }
  }
  return model;
}

function updateModelTranslationInGraph(model, ID, value, index) {
  if (ID == model.ID) {
    model.translation[index] = value;
  } else {
    for (var i = 0; i < model.children.length; i++) {
      model.children[i] = updateModelTranslationInGraph(
        model.children[i],
        ID,
        value,
        index
      );
    }
  }
  return model;
}

export default function sceneGraphReducer(
  state = initialState.sceneGraph,
  action
) {
  var world;
  switch (action.type) {
    case UPDATE_MODEL_SCALE:
      // For this example, just simulating a save by changing date modified.
      // In a real app using Redux, you might use redux-thunk and handle the async call in fuelSavingsActions.js
      world = updateModelScaleInGraph(
        state.world,
        action.ID,
        action.value,
        action.index
      );

      return objectAssign({}, state, { world });

    case UPDATE_MODEL_ROTATION:
      // For this example, just simulating a save by changing date modified.
      // In a real app using Redux, you might use redux-thunk and handle the async call in fuelSavingsActions.js
      world = updateModelRotationInGraph(
        state.world,
        action.ID,
        action.value,
        action.index
      );

      return objectAssign({}, state, { world });

    case UPDATE_MODEL_TRANSLATION:
      // For this example, just simulating a save by changing date modified.
      // In a real app using Redux, you might use redux-thunk and handle the async call in fuelSavingsActions.js
      world = updateModelTranslationInGraph(
        state.world,
        action.ID,
        action.value,
        action.index
      );

      return objectAssign({}, state, { world });
    default:
      return state;
  }
}
