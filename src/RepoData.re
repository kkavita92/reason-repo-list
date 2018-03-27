/* Record type: like a JS object except list of properties
   that it has and what their types are is fixed. */
/* Other modules can reference our repo type as RepoData.repo*/
type repo = {
  full_name: string,
  stargazers_count: int,
  html_url: string,
};
