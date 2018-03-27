let component = ReasonReact.statelessComponent("App");

let str = ReasonReact.stringToElement;

let make = _children => {
  ...component,
  render: _self =>
    <div className="App"> <h1> (str("Reason Projects")) </h1> </div>,
};
