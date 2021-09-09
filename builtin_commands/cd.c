#include "../mini.h"

static void	change_oldpwd_and_pwd(t_matur *matur, char *pwd, char *old_pwd)
{
	if (search_element_in_list_on_key(&matur->env, "OLDPWD"))
		replace_value(&matur->env, "OLDPWD", old_pwd);
	else
		add_element(&matur->env, new_element("OLDPWD", old_pwd));
	if (search_element_in_list_on_key(&matur->env, "PWD"))
		replace_value(&matur->env, "PWD", pwd);
	else
		add_element(&matur->env, new_element("PWD", pwd));
}

static void	chdir_to_env_variable_value(t_matur *matur, char *destination)
{
	char	*old_pwd;
	char	*pwd;

	pwd = search_element_in_list_on_key(&matur->env, destination);
	if (!pwd)
	{
		my_puterror("cd: ", destination, " not set");
		matur->error = 1;
		return ;
	}
	else
		old_pwd = getcwd(NULL, 0);
	chdir(pwd);
	change_oldpwd_and_pwd(matur, pwd, old_pwd);
	matur->error = 0;
}

void	my_cd(t_matur *matur)
{
	char	*old_pwd;
	char	*pwd;

	if (matur->mass[1] == NULL || !(my_strncmp(matur->mass[1], "--", 3)))
		chdir_to_env_variable_value(matur, "HOME");
	else if (!(my_strncmp(matur->mass[1], "-", 2)))
		chdir_to_env_variable_value(matur, "OLDPWD");
	else
	{
		old_pwd = getcwd(NULL, 0);
		if (chdir(matur->mass[1]) == -1)
		{
			my_puterror("cd:", matur->mass[1], ": No such file or directory");
			matur->error = 1;
		}
		else
		{
			pwd = getcwd(NULL, 0);
			change_oldpwd_and_pwd(matur, pwd, old_pwd);
			matur->error = 0;
		}
	}
}
