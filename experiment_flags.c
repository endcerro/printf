char *process_0(c_contr *controller)
{
	int i;
	char *output;
	char out;
	int nb;

	nb = 0;
	out = '0';
	i = 0;
	*(controller->pos) += 1;
	output = NULL;
	nb = ft_atoi(controller->str_in + *(controller->pos));
	while(isnumber(controller->str_in[*(controller->pos) + i]))
		i++;
	if(controller->str_in[*(controller->pos)] == '*' && ++i)
		nb = va_arg(*(controller->args), int);	
	if(controller->str_in[*(controller->pos) + i] == '.')
		out = ' ';
	*(controller->pos) += i;
	output = process_flag(controller);
	if((int)ft_strlen(output) < nb)
		output = append_char(output,out, nb, 1); 
	return(output);
}

char *append_char(char *base, char to_add, int count, int order)
{
	int i;
	char *out;
	char *filler;

	i = -1;
	count -= (int)ft_strlen(base);
	if(!(filler = malloc(sizeof(char) * (count + 1))))
		return NULL;
	while (++i < count)
		filler[i] = to_add;
	filler[i] = '\0';
	if (order = 1)
		out = ft_strjoin(zeros, base);
	else
		out = ft_strjoin(base, zeros);
	free(output); 
	free(zeros);	
	return(out)
}