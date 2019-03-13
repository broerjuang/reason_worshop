let rec fibNumber = num => {
  switch (num) {
  | 1
  | 2 => 1
  | num => fibNumber(num - 1) + fibNumber(num - 2)
  };
};

let sumEvenFibonacci = n => {
  let sum = ref(0);
  for (i in 1 to n) {
    if (fibNumber(i) mod 2 == 0) {
      sum := sum^ + fibNumber(i);
    };
  };
  sum^;
};

Js.log(sumEvenFibonacci(20));