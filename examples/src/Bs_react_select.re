[@bs.module "react-select"]
external select: ReasonReact.reactClass = "default";

let make = (~options, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=select,
    ~props={"options": options},
    children,
  );