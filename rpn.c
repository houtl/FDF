#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int isnb(char *c)
{
		if ((*c >= '0' && *c <= '9') || ((*c == '+' || *c == '-') && c[1] >= '0' && c[1] <= '9'))
					return (1);
			else
						return (0);
}

int main(int ac, char **av)
{
		char	*c;
			int		tab[4096];
				int		i;

					if (ac != 2)
							{
										printf("Error\n");
												return (0);
													}
						c = av[1];
							i = 0;
								while (*c)
										{
													while (*c == ' ')
																	c++;
															while (isnb(c))
																		{
																						tab[i++] = atoi(c);
																									while (*c != ' ' && *c)
																														c++;
																												while (*c == ' ')
																																	c++;
																														}
																	if ((*c != 0 && i < 2) || (*c == 0 && i != 1))
																				{
																								printf("Error\n");
																											return (0);
																													}
																			if (*c == '/' || *c == '%')
																							if (tab[i - 1] == 0)
																											{
																																printf("Error\n");
																																				return (0);
																																							}
																					if (*c == '+')
																									tab[i - 2] = tab[i - 2] + tab[i - 1];
																							if (*c == '-')
																											tab[i - 2] = tab[i - 2] - tab[i - 1];
																									if (*c == '*')
																													tab[i - 2] = tab[i - 2] * tab[i - 1];
																											if (*c == '/')
																															tab[i - 2] = tab[i - 2] / tab[i - 1];
																													if (*c == '%')
																																	tab[i - 2] = tab[i - 2] % tab[i - 1];
																															if (*c != 0)
																																		{
																																						c++;
																																									i--;
																																											}
																																}
									i == 1 ? printf("%d\n", tab[i - 1]) : printf("Error\n");
										return (0);
}
