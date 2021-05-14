/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libutils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 10:51:51 by fdexheim          #+#    #+#             */
/*   Updated: 2019/09/18 14:45:10 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUTILS_H
# define LIBUTILS_H

# define GFI_BUFF_SIZE 64

# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/dir.h>

char			**build_argv(char *src);
void			advance_quote(char **s);
void			advance_word(char **s);
void			advance_argv(char **s);
int				wordlen_quote(const char *s);
int				wordlen_word(const char *s);
void			ft_bzero(void *s, size_t n);
void			ft_free_string_tab(char **tab);
char			*ft_get_full_input();
size_t			ft_get_string_table_size(char **table);
int				ft_atoi(char *src);
bool			ft_check_nb_args_required(char **args, uint32_t nb_arg);
bool			ft_directory_exists(char *access);
void			ft_dump_brute(void *data, uint32_t size);
void			ft_dump_string_array(char **array);
bool			ft_file_exists(char *access);
bool			ft_file_or_directory_exists(char *access);
bool			ft_is_flag(char *arg);
bool			ft_is_quote(char c);
bool			ft_isdigit(int c);
char			*ft_itoa_uint64(uint64_t src);
char			ft_lowercase(const char c);
void			ft_put_size_t(const size_t src);
void			ft_put_size_t_hex(const size_t src);
void			ft_put_unsigned_char_hex(const unsigned char c);
void			ft_putchar(const char c);
void			ft_putnbr_bits(size_t src, const uint8_t bits);
void			ft_putstr(const char *str);
void			ft_putstr_endl(const char *str);
uint32_t		ft_reverse_endianess32(const uint32_t src);
uint64_t		ft_reverse_endianess64(const uint64_t src);
void			ft_sort_string_table(char **table);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *src);
char			*ft_strjoin(const char *s1, const char *s2);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t size);
bool			ft_testbit(uint32_t value, uint8_t bit_number);
char			**ft_tokenizer(char *src);
char			*ft_truncated_filename(char *path);
char			*ft_valid_quote(char *s);
bool			yes_no_confirm(char *question);

#endif
