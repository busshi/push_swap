![checker](https://github.com/busshi/push_swap/actions/workflows/checker.yml/badge.svg)

[![aldubar's 42Project Score](https://badge42.herokuapp.com/api/project/aldubar/push_swap)](https://github.com/JaeSeoKim/badge42)


# PUSH_SWAP

<p align="center">
	<img src="./assets/push_swap.gif" >
</p>

The push_swap program calculates and displays on the standard ouptut
the instructions allowing to sort the integers passed as parameters.

The checker program allows you to check the sorting instructions.
Combined with the push_swap program,
it checks if the instructions to sort the numbers are good.


Makefile:

- make: compile project
- make check: compile the project and run evaluation tests



push_swap usage:
```bash
ARG="-12 -50 101 2 -3"; ./push_swap $ARG
```


checker usage:
```bash
ARG="-12 -50 101 2 -3"; ./checker $ARG
```


push_swap + checker usage:
```bash
ARG="-12 -50 101 2 -3"; ./push_swap $ARG | ./checker $ARG
```
