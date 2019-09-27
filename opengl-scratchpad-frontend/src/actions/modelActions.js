import * as types from "../constants/actionTypes";

// // example of a thunk using the redux-thunk middleware
// export function saveFuelSavings(settings) {
//   return function (dispatch) {
//     // thunks allow for pre-processing actions, calling apis, and dispatching multiple actions
//     // in this case at this point we could call a service that would persist the fuel savings
//     return dispatch({
//       type: types.SAVE_FUEL_SAVINGS,
//       dateModified: getFormattedDateTime(),
//       settings
//     });
//   };
// }

export function updateScale(ID, value, index) {
  return {
    type: types.UPDATE_MODEL_SCALE,
    ID,
    value,
    index
  };
}

export function updateRotation(ID, value, index) {
  return {
    type: types.UPDATE_MODEL_ROTATION,
    ID,
    value,
    index
  };
}

export function updateTranslation(ID, value, index) {
  return {
    type: types.UPDATE_MODEL_TRANSLATION,
    ID,
    value,
    index
  };
}
