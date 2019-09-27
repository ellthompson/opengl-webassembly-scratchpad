import { combineReducers } from "redux";
import sceneGraph from "./sceneGraphReducer.js";
import { connectRouter } from "connected-react-router";

const rootReducer = history =>
  combineReducers({
    router: connectRouter(history),
    sceneGraph
  });

export default rootReducer;
