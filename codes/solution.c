
void    recursive_sort_even(int chunk)
{
    if (chunk == 2)
        sort_top_three_rest();
    else if (chunk == 3)
        sort_top_three();
    else
        recursive_sort_even(chunk / 2);
}

void    recursive_sort(int chunk) // 6 13 25 50
{
    if (chunk == 2)
        sort_top_three_rest();
    else if (chunk == 3)
        sort_top_three();
    else
    {
        set_pivot(chunk);
        divide_b(chunk);
        if (chunk > 7)
        {
            recursive_sort_even(chunk / 2);
            if (chunk % 2 == 0)
            {
                recursive_sort((chunk / 2) / 2);
                if (chunk > 12)
                    recursive_sort((chunk / 2) / 2 + 1)
            }
        }
        recursive_sort(chunk - (chunk / 2));
    }
}

void    sort(chunk) //chunk 의미: chunk 갯수의 범위안에 속하는 수들의 모임
{
    if (b->top == 0)
        return ;
    else
        chunk_sort(chunk);
    sort(b->size - (b->top + 1));
}