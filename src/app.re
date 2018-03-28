type state = {repoData: option(array(RepoData.repo))};

type action =
  | Loaded(array(RepoData.repo));

let component = ReasonReact.reducerComponent("App");

/*Name of constant and RepoData.Repo is the type we are annotating it
  with. Reason can infer types but it is useful to include annotation so
  typechecker can let us know if we have made a mistake*/
let dummyRepos: array(RepoData.repo) = [|
  {
    stargazers_count: 27,
    full_name: "jsdf/reason-react-hacker-news",
    html_url: "https://github.com/jsdf/reason-react-hacker-news",
  },
  {
    stargazers_count: 93,
    full_name: "reasonml/reason-tools",
    html_url: "https://github.com/reasonml/reason-tools",
  },
|];

/* Reason's JSX doesn't allow you to display text by putting it directly
   between JSX tags. Strings are also always double quoted. */
let str = ReasonReact.stringToElement;

let make = _children => {
  ...component,
  initialState: () => {repoData: None},
  reducer: (action, _state) =>
    switch (action) {
    | Loaded(loadedRepo) => ReasonReact.Update({repoData: Some(loadedRepo)})
    },
  render: self => {
    let loadReposButton =
      <button onClick=(self.reduce(_event => Loaded(dummyRepos)))>
        (str("Load Repos"))
      </button>;
    let repoItems =
      switch (self.state.repoData) {
      | Some(repos) =>
        ReasonReact.arrayToElement(
          Array.map(
            (repo: RepoData.repo) => <RepoItem key=repo.full_name repo />,
            repos,
          ),
        )
      | None => loadReposButton
      };
    <div className="App">
      <h1> (str("Reason Projects")) </h1>
      repoItems
    </div>;
  },
};
