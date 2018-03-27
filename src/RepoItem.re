let component = ReasonReact.statelessComponent("RepoItem");

let str = ReasonReact.stringToElement;

/* make function returns a record. First thing is ...component
   where component is the return value of RR.reducerComponent or
   RR.statelessComponent */
let make = (~repo: RepoData.repo, _children) => {
  ...component,
  render: _self =>
    <div className="RepoItem">
      <a href=repo.html_url> <h2> (str(repo.full_name)) </h2> </a>
      (str(string_of_int(repo.stargazers_count) ++ " stars"))
    </div>,
};
/* Above we have a stateless component which takes one prop - repo -
   from RepoData module and renders a div */
