let rec fib = x =>
  if (x <= 1) {
    1;
  } else {
    fib(x - 1) + fib(x - 2);
  };

let rec sum = mylist => {
  switch (mylist) {
  | [] => 0
  | [hd, ...tl] => hd + sum(tl)
  };
};

let sumFibEven = x => {
  Array.init(x, n => fib(n))
  	|> Array.to_list
	|> List.filter(value => value mod 2 == 0)
	|> sum
}

Js.log2("hasil", sumFibEven(6))