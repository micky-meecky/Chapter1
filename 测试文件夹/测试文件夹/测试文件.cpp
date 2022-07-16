void Union()
	{
		
		//扩大线性表，将B中不存在于A中的数插入到A中即可，暂时不涉及排序
		//先获取A，B的长度
		
		//遍历B
		
		for (int i = 0; i < len_LB; i++)
		{
			int j = 0;
			int flag = 0;
			for (j = 0; j < len_LA; j++)
			{
				if (LB[i] == LA[j])
				{
					flag = 1;
					break;//遇到已存在的，就退出内循环。
				}
				else
				{
					continue;
				}
			}
			if (flag == 0)
			{
				//需要先将LA的长度变长再把数赋给它
				this->Extend(&LA[0], &len_LA, LB[i]);
			}
		}
		//打印结果
		display(LA, len_LA);
	}