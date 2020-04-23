/*
** EPITECH PROJECT, 2020
** mini_shell.h
** File description:
** Header for my current project
*/

#ifndef MINI_SHELL_1_H
#define MINI_SHELL_1_H

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>


enum shell_state {USING, EXITING};

typedef struct main_info {
    enum shell_state shell_state;
    char **envp;
    char *home_path;
    char *last_dir;

    char *entire_path;
    char **paths;
    int is_path_unset;
    int return_value;
} main_info_t;

int start_mini_shell(char **envp);
main_info_t *init_shell(char **envp);
void init_shell_follow_up(main_info_t *infos);
int ask_input(main_info_t *infos);
int launch_main_loop(main_info_t *infos);
int is_a_known_command(main_info_t *infos, char **word_array);
int terminate_shell(main_info_t *infos);
void change_env(main_info_t *infos, char *to_change, char *new_env);
char *get_new_var_name(char **word_array, int nbr_args);
void set_new_env_name_variable_follow_up(main_info_t *infos, int bool_exists,
    int i, char *new_var);
void set_new_env_name_variable(main_info_t *infos, char **word_array,
    int nbr_args);
void continue_setenv_checks_follow_up(main_info_t *infos,
    char **word_array, int nbr_args);
void try_put_env_in_paths(main_info_t *infos, char *curr_path);

void enter_directory(main_info_t *infos, char *path);
void try_enter_dir(main_info_t *infos, char **word_array);
int go_last_dir(main_info_t *infos, char **word_array);

void handle_other_commands(main_info_t *infos, char **word_array);
void search_program(main_info_t *infos, char **word_array);
char *search_path(main_info_t *infos, char **word_array);

void set_first_path(main_info_t *infos, char *curr_path);
void set_middle_paths(main_info_t *infos, int nbr_paths, char *curr_path);
void set_last_path(main_info_t *infos, int nbr_paths, char *curr_path);
void update_paths(main_info_t *infos);

void continue_check_for_programm_execution(main_info_t *infos,
    char *found_path, char **word_array);

char *try_to_find_env_var(char *to_find, char *curr_test,
    int var_name_len);

void handle_unsetenv(main_info_t *infos, char **word_array);
void handle_setenv(main_info_t *infos, char **word_array);
void handle_env(main_info_t *infos);
void handle_cd(main_info_t *infos, char **word_array);
void handle_exit(main_info_t *infos, char **word_array);

void execute_program(main_info_t *infos, char *found_path, char **word_array);

/* Expression handlers */

char ***get_all_commands(char *line, int nbr_commands);
void handle_list_of_commands(main_info_t *infos, char *line);
int does_command_contain_expression(main_info_t *infos, char **command);
void handle_redirect_output(main_info_t *infos, char **command,
    int expr_position);
void handle_redirect_output_append(main_info_t *infos, char **command,
    int expr_position);
void handle_redirect_input(main_info_t *infos, char **command,
    int expr_position);
void handle_redirect_input_double(main_info_t *infos, char **command,
    int expr_position);

/* Expression errors */

int check_errors_redirect_output(char **command,
    int nbr_args, int expr_position);
int check_errors_redirect_output_append(char **command, int nbr_args,
    int expr_position);
int check_errors_redirect_input(char **command, int nbr_args,
    int expr_position);
int check_errors_redirect_input_double(char **command, int nbr_args,
    int expr_position);


/* Expression utils */

char **remove_arg_from_command(char **command, int index_to_rem);

#endif