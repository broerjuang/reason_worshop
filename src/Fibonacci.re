let rec lastfibnum = x => {
  switch (x) {
  | 0 => 0
  | 1
  | 2 => 1
  | x => lastfibnum(x - 1) + lastfibnum(x - 2)
  };
};

let rec sum = x => {
  switch (x) {
  | [] => 0
  | [hd, ...tl] => hd + sum(tl)
  };
};

let listFib = x => Array.init(x, n => lastfibnum(n + 1));

let sumOfEvenFib = x =>
  x
  |> listFib
  |> Array.to_list
  |> List.filter(value => value mod 2 == 0)
  |> sum;

Js.log(lastfibnum(9));
Js.log(listFib(9));
Js.log(sumOfEvenFib(9));