/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:21:27 by vapetros          #+#    #+#             */
/*   Updated: 2024/09/22 21:01:48 by vapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define DEFAULT_DICT "default.dict"

typedef enum e_err_code
{
	ARG_ERROR,
	DICT_ERROR
}	t_err_code;

typedef struct s_dict_entry
{
	char	*number;
	char	*text;
}	t_dict_entry;

int				handle_error(t_err_code err_code);
int				is_space(char c);
int				is_valid_number(char *str);
char			*ft_strncat(char *dest, char *src, unsigned int nb);
char			*ft_strcpy(char *dest, char *src);
char			*append_to_content(char *content, char *buffer, int bytes_read,
					int *total_size);
char			*read_file(int fd);
char			*read_file_content(char *filename);
int				ft_strlen(char *str);
char			*ft_strdup(char *src);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
char			*ft_strchr(const char *s, int c);
char			*lookup_number_in_dict(char *number, t_dict_entry *dictionary);
int				ft_strcmp(char *s1, char *s2);
t_dict_entry	*parse_dictionary(char *dict_content);
char			*combine_strings(char *str1, char *str2);
char			*ft_itoa(int num);
char			*handle_large_number(char *number, t_dict_entry *dictionary);
char			*convert_number_to_text(char *number, t_dict_entry *dictionary);
void			ft_putstr(char *str);
char			*lookup_number_in_dict(char *number, t_dict_entry *dictionary);
char			*convert_simple_tens(char *number, t_dict_entry *dictionary);
char			*convert_two_digit_tens(char *result, t_dict_entry *dictionary,
					char *ones);
char			*convert_general_tens(char *result, t_dict_entry *dictionary,
					int num);
char			*convert_number_to_text(char *number, t_dict_entry *dictionary);
char			*process_hundred(char *number, t_dict_entry *dictionary);
char			*process_tens_and_ones(char *result, char *number,
					t_dict_entry *dictionary);
char			*process_number_hundreds(char *number,
					t_dict_entry *dictionary);
int				is_all_zeros(char *str);
int				get_chunk_len(int len);
int				get_num_pos(char *arg);

#endif
