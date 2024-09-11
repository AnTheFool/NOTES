# **PISANO'S PERIOD**

Pisano's period, also known as the Fibonacci sequence modulo a number, refers to the repeating pattern that emerges when the Fibonacci sequence is taken modulo a specific number.

When the Fibonacci sequence is taken modulo a number, the resulting sequence is periodic, meaning that it repeats itself after a certain number of terms. This repeating pattern is called Pisano's period. The length of Pisano's period depends on the chosen modulus.

For example, if we take the Fibonacci sequence modulo 3, we get the following sequence:

```
0, 1, 1, 2, 0, 2, 2, 1, 0, 1, 1, 2, 0, 2, 2, 1, 0, 1, 1, 2, 0, 2, 2, 1, ...
```

In this case, Pisano's period has a length of 8. Similarly, if we take the Fibonacci sequence modulo 5, we get the following sequence:

```
0, 1, 1, 2, 3, 0, 3, 3, 1, 4, 0, 4, 4, 3, 2, 0, 2, 2, 4, 1, 0, 1, 1, 2, 3, ...
```

In this case, Pisano's period has a length of 20.

### Why does this period exist ? 

For modulo m, the period length is upper bounded by m²

Let us consider below m²+1 ordered pairs


$$(F_0, F_1), (F_1, F_2), \ldots ,(F_{m^2}, F_{m^2+1})$$


If we consider remainders of all pairs with m, we can claim , there will be at least two pairs with some remainders
$$
(F_i \% m, F_{i+1} \% m) =  (Fj \% m, F_{j+1} \% m) \\ 
\Longleftrightarrow F_i \% m = F_j \% m \space \space (i<j \leq m^2) \\
\Longleftrightarrow F_{i+1} \% m = F_{j+1} \% m
$$

Please note the sequences starting from $F_i$ and $F_j$ and generated using $(F_i, F_{i+1})$ and $(F_j , F_{j+1})$ respectively. So $F_{i+k} \% m = F_{j+k} \% m$