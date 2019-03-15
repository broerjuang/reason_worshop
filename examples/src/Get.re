module type Config = {type t;};

module Make = (C: Config) => {
  type state =
    | Idle
    | Error(string)
    | Loading
    | Loaded(C.t);

  type action =
    | FetchRequested
    | FetchSucceed(C.t)
    | FetchFailed(string);

  let component = ReasonReact.reducerComponent("Get");

  let make = (~url, ~readResponse, children) => {
    ...component,
    initialState: () => Idle,
    reducer: (action, _state) => {
      switch (action) {
      | FetchRequested =>
        ReasonReact.UpdateWithSideEffects(
          Loading,
          self =>
            Js.Promise.(
              Bs_fetch.fetch(url)
              |> then_(Bs_fetch.Response.json)
              |> then_(response => {
                   let todos = readResponse(response);
                   self.send(FetchSucceed(todos)) |> resolve;
                 })
              |> catch(_error =>
                   self.send(FetchFailed("Fetch todos failed")) |> resolve
                 )
              |> ignore
            ),
        )
      | FetchSucceed(todos) => ReasonReact.Update(Loaded(todos))
      | FetchFailed(message) => ReasonReact.Update(Error(message))
      };
    },
    didMount: self => {
      self.send(FetchRequested);
    },
    render: self => {
      children(self.state);
    },
  };
};