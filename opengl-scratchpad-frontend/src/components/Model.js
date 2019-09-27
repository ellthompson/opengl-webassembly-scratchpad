import React, { Component } from "react";
import PropTypes from "prop-types";

class Model extends Component {
  constructor(props) {
    super(props);
    this.state = {
      transform: [props.scale, props.rotation, props.translation]
    };
  }
  handleChange = (value, transformType, dimension) => {
    console.log(value);
    var newState = this.state;
    newState.transform[transformType][dimension] = value;
    this.setState(newState);
  };
  render() {
    var {
      modelFilename,
      children,
      ID,
      scale,
      rotation,
      translation,
      transformUpdates
    } = this.props;
    var transform = [scale, rotation, translation];
    var transformNames = ["scale", "rotation", "translation"];
    return (
      <div>
        <div>
          <span>Model filename:</span>
          <input
            className="small"
            name="model filename"
            type="text"
            value={modelFilename}
            onChange={() => {}}
          />
        </div>
        <div>
          {transform.map((t, i) => {
            return (
              <div key={i}>
                <span>{transformNames[i]}:</span>
                <div>
                  <span>x:</span>
                  <input
                    className="small"
                    name={transformNames[i] + " x"}
                    type="number"
                    defaultValue={this.state.transform[i][0]}
                    onChange={e => this.handleChange(e.target.value, i, 0)}
                    onBlur={() =>
                      transformUpdates[i](ID, this.state.transform[i][0], 0)
                    }
                  />
                  <span>y:</span>
                  <input
                    className="small"
                    name={transformNames[i] + " y"}
                    type="number"
                    defaultValue={this.state.transform[i][1]}
                    onChange={e => this.handleChange(e.target.value, i, 1)}
                    onBlur={() =>
                      transformUpdates[i](ID, this.state.transform[i][1], 1)
                    }
                  />
                  <span>z:</span>
                  <input
                    className="small"
                    name={transformNames[i] + " z"}
                    type="number"
                    defaultValue={this.state.transform[i][2]}
                    onChange={e => this.handleChange(e.target.value, i, 2)}
                    onBlur={() =>
                      transformUpdates[i](ID, this.state.transform[i][2], 2)
                    }
                  />
                </div>
              </div>
            );
          })}
        </div>
        <div>
          {children.map(c => (
            <Model key={c.ID} {...c} transformUpdates={transformUpdates} />
          ))}
        </div>
      </div>
    );
  }
}
//
// const { string, func, number, oneOfType } = PropTypes;
//
// Model.propTypes = {
//   name: string.isRequired,
//   onChange: func.isRequired,
//   placeholder: string,
//   value: oneOfType([string, number])
// };

export default Model;
