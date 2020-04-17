/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** This is the file that contains the main function for the project
*/

#include "my.h"
#include "mini_shell.h"

int main(int ac, char **av, char **envp)
{
    return (start_mini_shell(envp));
}