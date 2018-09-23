# Boolean-Function-Maker
A simple Boolean Function Maker in C++

## What the heck?

I get the idea to make a boolean function maker from the Nand2Tetris course.

In fact, for those of you who don't know it, you can create a boolean function by checking
the so called "Truth Table" and picking up the rows in which the value of the  function is 1. At this point you should create a unique condition for which the row is true only in that particular case. You can also concatenate more expression by using the "OR" boolean function.

For example, if we check the Truth Table of the XOR boolean expression, what we get is:

```
a    b   Xor
0    0   0
0    1   1
1    0   1
1    1   0
```

So, XOR gets 1 when:

```
a and NOT b OR b and NOT a
```
