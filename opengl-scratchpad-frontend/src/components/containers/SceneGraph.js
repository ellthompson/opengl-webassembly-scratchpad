import React from "react";
import PropTypes from "prop-types";
import { connect } from "react-redux";
import { bindActionCreators } from "redux";
import * as actions from "../../actions/modelActions";
import Model from "../Model";

export class SceneGraph extends React.Component {
  updateScale = (ID, value, index) => {
    this.props.actions.updateScale(ID, value, index);
  };
  updateRotation = (ID, value, index) => {
    this.props.actions.updateRotation(ID, value, index);
  };
  updateTranslation = (ID, value, index) => {
    this.props.actions.updateTranslation(ID, value, index);
  };

  render() {
    return (
      <Model
        {...this.props.sceneGraph["world"]}
        transformUpdates={[
          this.updateScale,
          this.updateRotation,
          this.updateTranslation
        ]}
      />
      // <FuelSavingsForm
      //   onSaveClick={this.saveFuelSavings}
      //   onChange={this.calculateFuelSavings}
      //   fuelSavings={this.props.fuelSavings}
      // />
    );
  }
}

// FuelSavingsPage.propTypes = {
//   actions: PropTypes.object.isRequired,
//   fuelSavings: PropTypes.object.isRequired
// };

function mapStateToProps(state) {
  return {
    sceneGraph: state.sceneGraph
  };
}

function mapDispatchToProps(dispatch) {
  return {
    actions: bindActionCreators(actions, dispatch)
  };
}

export default connect(mapStateToProps, mapDispatchToProps)(SceneGraph);
