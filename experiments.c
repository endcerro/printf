

char *process(c_contr *controller)
{
	char *output;
	char c_to_s[2];
	char *tmp[2];

	
	if ((controller->str_in)[*(controller->pos)] == '\0')
		return (ft_strdup(""));
	c_to_s[1] = '\0';
	output = NULL;
	if ((controller->str_in)[*(controller->pos)] == '%')
		tmp[0] = process_flag(controller);
	else if ((tmp[0] = &c_to_s))
		c_to_s[0] = (controller->str_in)[*(controller->pos)];
	tmp[1] = process(controller);
	*(controller->pos) += 1;
	output = ft_strjoin(tmp[0], tmp[1])	
	free(tmp[0]);
	free(tmp[1]);
	return (output);
}

int ft_printf(const char *str_in, ...)
{
	struct c_list 	*controller;
	char 			*to_print;
	int 			len[2];
	int 			pos;
	va_list 		args;
	
	if (!(controller = malloc(sizeof(c_contr))))
 		return (0);
 	va_start(args, str_in);
	vars[0] = 0;
	vars[1] = 0;
 	controller->str_in = (char *)str_in;
 	controller->args = &args;
 	controller->len = &vars;
 	controller->pos = &vars + 1;
   	to_print = process(controller);
   	ft_putsr(to_print);
   	vars[0] += ft_strlen(to_print);
   	free(to_print);
   	return (vars[0]);
}

char *process_type(c_contr *controller)
{
	char *output;
	char *temp;
	char c;

	output = NULL;

	c = controller->str_in[*(controller->pos)]; 
	if(c == 'd' || c == 'i')
		output =  ft_itoa(va_arg(*(controller->args), int));
	else if(c == 'u')
		output = ft_ultoa(va_arg(*(controller->args), unsigned int));
	else if(c == '%' || c == 'c')
	{
		//Malloc necessqire ?
		if(!(output = malloc(sizeof(char) * 2)))
			return (NULL);
		output[0] = '%';
		if(c == 'c')
			output[0] = va_arg(*(controller->args), int);
		output[1] = '\0';	
	}
	else if(c == 's')
		output = ft_strdup(va_arg(*(controller->args), const char*));
	else if(c == 'p')
	{
		temp = ft_convert_base(ft_ultoa(va_arg(*(controller->args),
		 unsigned long)), "0123456789", "0123456789abcdef");
		output = ft_strjoin("0x", temp);
		free(temp);
	}
	else if(c == 'X' || c == 'x')
	{	
		temp = ft_ultoa((unsigned long)va_arg(*(controller->args), unsigned int));
		if(c == 'x')
			output = ft_convert_base(temp, "0123456789", "0123456789abcdef");
		else
			output = ft_convert_base(temp,"0123456789", "0123456789ABCDEF");
		free(temp);
	}
	//Pas sur du &&
	if(output == NULL && c == 's')
		*(controller->len) += 1;
	*(controller->pos) += 1;
	return output;
}