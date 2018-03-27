let component = ReasonReact.statelessComponent("App");

/* Reason's JSX doesn't allow you to display text by putting it directly
   between JSX tags. Strings are also always double quoted. */
let str = ReasonReact.stringToElement;

let make = _children => {
  ...component,
  render: _self => {
    /*Name of constant and RepoData.Repo is the type we are annotating it
      with. Reason can infer types but it is useful to include annotation so
      typechecker can let us know if we have made a mistake*/
    let dummyRepo: RepoData.repo = {
      stargazers_count: 27,
      full_name: "jsdf/reason-react-hacker-news",
      html_url: "https://github.com/jsdf/reason-react-hacker-news",
    };
    <div className="App">
      <h1> (str("Reason Projects")) </h1>
      <RepoItem repo=dummyRepo />
    </div>;
  },
};
