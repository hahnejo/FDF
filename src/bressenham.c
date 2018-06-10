// t_Vector2d **plotLineLow(t_Vector2d *start, t_Vector2d *end)
// {
// 	t_Vector2d **points;

// 	points = ft_memalloc(((end->x - start->x) + 1) * sizeof(t_Vector2d*));
// 	float dx = end->x - start->x;
// 	float dy = end->y - start->y;
// 	float yi = 1;
// 	if (dy < 0)
// 	{
// 		yi = -1;
// 		dy *= -1;
// 	}
// 	float D = 2 * dy - dx;
// 	float y = start->y;
// 	int i = 0;

// 	for (float x = start->x; x < end->x; x++)
// 	{
// 		points[i] = newVec(x, y);
// 		if (D > 0)
// 		{
// 			y += yi;
// 			D -= 2 * dx;
// 		}
// 		D += 2 * dy;
// 		i++;
// 	}
// 	return points;
// }

// t_Vector2d **plotLineHigh(t_Vector2d *start, t_Vector2d *end)
// {
// 	t_Vector2d **points;

// 	points = ft_memalloc(((end->y - start->y) + 1) * sizeof(t_Vector2d*));
// 	float dx = end->x - start->x;
// 	float dy = end->y - start->y;
// 	float xi = 1;
// 	if (dx < 0)
// 	{
// 		xi = -1;
// 		dy *= -1;
// 	}
// 	float D = 2 * dx - dy;
// 	float x = start->x;
// 	int i = 0;

// 	for (float y = start->y; y < end->y; y++)
// 	{
// 		points[i] = newVec(x, y);
// 		if (D > 0)
// 		{
// 			x += xi;
// 			D -= 2 * dy;
// 		}
// 		D += 2 * dx;
// 		i++;
// 	}
// 	return points;
// }

// void plotLine(t_window *win, t_Vector2d *start, t_Vector2d *end)
// {
// 	t_Vector2d **points;
// 	if (fabsf(end->y - start->y) < fabsf(end->x - start->x))
// 	{
// 		if (start->x > end->x)
// 			points = plotLineLow(end, start);
// 		else
// 			points = plotLineLow(start, end);
// 	}
// 	else
// 	{
// 		if (start->y > end->y)
// 			points = plotLineHigh(end, start);
// 		else
// 			points = plotLineHigh(start, end);
// 	}
// 	for (int i = 0; points[i]; i++)
// 	{
// 		mlx_pixel_put(win->mlx_ptr, win->win_ptr, points[i]->x, points[i]->y, 0xFFFFFF);
// 	}
// 	points = free_list(points);
// }