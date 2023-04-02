#include "../../includes/minishell.h"

int	ft_cd(t_data *data)
{
	char	**str[2];
	char	*tmp;

	g_status_number = 0;
	str[0] = ((t_cmd *)data->cmds->content)->f_cmd;
	tmp = ft_get_envalue("HOME", data->env, 4);
	if (!tmp)
		tmp = ft_strdup("");
	str[1] = ft_extend_split(NULL, tmp);
	free(tmp);
	tmp = getcwd(NULL, 0);
	str[1] = ft_extend_split(str[1], tmp);
	free(tmp);
	ft_cd_error(str);
	if (!g_status_number)
		data->env = ft_search_env("OLDPWD", str[1][1], data->env, 6);
	tmp = getcwd(NULL, 0);
	if (!tmp)
		tmp = ft_strdup("");
	str[1] = ft_extend_split(str[1], tmp);
	free(tmp);
	data->env = ft_search_env("PWD", str[1][2], data->env, 3);
	ft_free_split(&str[1]);
	return (g_status_number);
}