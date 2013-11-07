/**
** Renvoie un groupe de 2 nombres maximum
** a la position indiquée
** ex : 529 pos = 0 renvoie 29
**      pos = 1 renvoie 5
*/
int get_group_num(int nb, int pos)
{
	int group;

	group = get_nb_at_pos(nb, pos * 2);
	group = group + 10 * get_nb_at_pos(nb, pos * 2 + 1);
	return(group);
}

/**
** On soustrait les impairs à partir du dernier impaire utilisé augmenté de 1
**	multiplié par 10 et augmenté de 1
*/
int get_to_sub(int last_sub)
{
	return ((last_sub + 1) * 10 + 1);
}
/**
** renvoie le nombre de la racine carré concerné par le groupe de chiffre
** Un peu moche les pointeurs mais bon...
*/
int treat_group(int group, int* rest, int* to_sub)
{
	int nb_sub;
	int sub;

	sub = *to_sub;
	group = group + *rest * 100;
	nb_sub = 0;
	while(group - sub >= 0)
	{
		group = group - sub;
		sub = sub + 2;
		nb_sub = nb_sub + 1;
	}
	*to_sub = sub - 2;
	*rest = group;
	return(nb_sub);
}

/**
** Il y a la méthode facile qui consiste a incrémenter un nombre qu'on multiplie à lui même
** Jusqu'a arriver au nombre voulu puis la méthode compliquée.
** J'ai choisi le vrai calcul de racine carrée :)
** Algo pris sur http://algor.chez.com/math/racine.htm
*/
int my_square_root(int nb)
{
	int len;
	int nb_group;
	int group;
	int square_part;
	int square_root;
	int to_sub;
	int rest;

	rest = 0;
	square_root = 0;
	len = get_nb_len(nb);
	nb_group = len / 2;
	if(len % 2 == 1)
	{
		nb_group = nb_group + 1; 	
	}
	to_sub = 1;
	while(nb_group > 0)
	{
		group = get_group_num(nb, nb_group - 1);
		square_part = treat_group(group, &rest, &to_sub);
		square_root = square_root * 10 + square_part;
		to_sub = get_to_sub(to_sub);
		nb_group = nb_group - 1;
	}
	if(rest == 0)
	{
		return (square_root);
	}
	else
	{
		return (0);
	}
	return (square_root);
}