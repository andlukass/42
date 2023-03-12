#include <stdio.h>
#include <unistd.h>

void write_error()
{
	char message[5] = "Error";
	char line = '\n';
	int i;

	i = 0;
	while (i < 5)
	{
		write(1, &message[i], 1);
		i++;
	}
	write(1, &line, 1);
}

int get_args_into_int(char *argv[], int *arguments)
{
	char valid_input[32] = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 32)
	{
		if (valid_input[i] != argv[1][i])
		{
			write_error();
			return (1);
		}
		if  (argv[1][i] >= 48 && argv[1][i] <= 57)
		{
			arguments[j] = argv[1][i] - '0';
			j++;
		}
		i++;
	}
	return (0);
}

void populate_with_args(int matriz[][6], int *arguments)
{
	matriz[0][1] = arguments[0];
	matriz[0][2] = arguments[1];
	matriz[0][3] = arguments[2];
	matriz[0][4] = arguments[3];
	matriz[5][1] = arguments[4];
	matriz[5][2] = arguments[5];
	matriz[5][3] = arguments[6];
	matriz[5][4] = arguments[7];
	matriz[1][0] = arguments[8];
	matriz[2][0] = arguments[9];
	matriz[3][0] = arguments[10];
	matriz[4][0] = arguments[11];
	matriz[1][5] = arguments[12];
	matriz[2][5] = arguments[13];
	matriz[3][5] = arguments[14];
	matriz[4][5] = arguments[15];
}

void initialize_matriz(int matriz[][6])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 6)
	{
		while (j < 6)
		{
			matriz[j][i] = 0;
			j++;
		}
		i++;
	}
}

int main(int argc, char *argv[])
{

	//      up   |   down  |  left  |  right
	//  "4 3 2 1 | 1 2 2 2 | 4 3 2 1 | 1 2 2 2"
	// first is the line, second is the column

	int matriz[6][6];
	int arguments[16]; //array that receive args from a.out
	int check_error;
	
	check_error = get_args_into_int(argv,arguments);
	if (check_error == 1)
	{
		return (0);
	}
	initialize_matriz(matriz);
	populate_with_args(matriz,arguments);

		//VERIFY 4 UP TO DOWN
		int control = 1;
        	for(int j=1; j<5;j++)
        	{
			if(matriz[0][j] == 4)
			{
				for(int k=1; k<5;k++)
				{
				matriz[k][j] = control;
				control++;
				}
			}
			control = 1;
        	}

		//VERIFY 4 DOWN TO UP
		control = 1;		
        	for(int j=6; j>=1;j--)
        	{	
			if(matriz[5][j] == 4)
			{
				for(int k=4; k>=1;k--)
				{
				matriz[k][j] = control;
				control++;
				}
			}
			control = 1;
        	}

		//VERIFY 4 LEFT TO RIGHT
		control = 1;		
        	for(int j=1; j<5;j++)
        	{
			if(matriz[j][0] == 4)
			{
				for(int k=1; k<5;k++)
				{
				matriz[j][k] = control;
				control++;
				}
			}
			control = 1;
        	}

		//VERIFY 4 RIGHT TO LEFT
		control = 1;		
        	for(int j=6; j>=1;j--)
        	{	
			if(matriz[j][5] == 4)
			{
				for(int k=4; k>=1;k--)
				{
				matriz[j][k] = control;
				control++;
				}
			}
			control = 1;
        	}

		//VERIFY DOUBLE 2 LEFT AND RIGTH
		for(int j=1; j<=5;j++)
		{
			if(matriz[j][0] == 2 && matriz[j][5] == 2)
			{
				if(matriz[j][1] == 3)
				{
					matriz[j][4] = 2;
				}
				if(matriz[j][4] == 3)
				{
					matriz[j][1] = 2;					
				}
			}
		}

		//VERIFY DOUBLE 2 UP AND DOWN
		for(int j=1; j<=5;j++)
		{
			if(matriz[0][j] == 2 && matriz[5][j] == 2)
			{
				if(matriz[1][j] == 3)
				{
					matriz[4][j] = 2;
				}
				if(matriz[4][j] == 3)
				{
					matriz[1][j] = 2;					
				}
			}
		}

		//VERIFY 3 AND 2 TO GET THE 4 UP TO DOWN
		for(int j=1; j<=5;j++)
		{
			if(matriz[0][j] == 3 && matriz[5][j] == 2)
			{
				matriz[3][j] = 4;
			}
		}

		//VERIFY 3 AND 2 TO GET THE 4 DOWN TO UP
		for(int j=1; j<=5;j++)
		{
			if(matriz[5][j] == 2 && matriz[0][j] == 3)
			{
				matriz[3][j] = 4;
			}
		}

		//VERIFY 3 AND 2 TO GET THE 4 RIGTH TO LEFT
		for(int j=1; j<=5;j++)
		{
			if(matriz[j][0] == 2 && matriz[j][5] == 3)
			{
				matriz[j][2] = 4;
			}
		}

		//VERIFY 3 AND 2 TO GET THE 4 LEFT TO RIGTH
		for(int j=1; j<=5;j++)
		{
			if(matriz[j][0] == 3 && matriz[j][5] == 2)
			{
				matriz[j][3] = 4;
			}
		}




		//VERIFY 3, 2 AND 4 TO GET THE 3 AND 1 UP
 		for(int j=1; j<=5;j++)
		{
			if(matriz[j][0] == 3 && matriz[j][1] == 2 && matriz[j][3] == 4)
			{
				matriz[j][2] = 3;
				matriz[j][4] = 1;
			}
		}

		//VERIFY 3, 2 AND 4 TO GET THE 3 AND 1 DOWN
		for(int j=1; j<=5;j++)
		{
			if(matriz[j][5] == 3 && matriz[j][4] == 2 && matriz[j][2] == 4)
			{
				matriz[j][1] = 1;
				matriz[j][3] = 3;
			}
		}
		//VERIFY 3, 2 AND 4 TO GET THE 3 AND 1 LEFT
		for(int j=1; j<=5;j++)
		{
			if(matriz[0][j] == 3 && matriz[1][j] == 2 && matriz[3][j] == 4)
			{
				matriz[2][j] = 3;
				matriz[4][j] = 1;
			}
		}
		//VERIFY 3, 2 AND 4 TO GET THE 3 AND 1 RIGTH  
		for(int j=1; j<=5;j++)
		{
			if(matriz[5][j] == 3 && matriz[4][j] == 2 && matriz[2][j] == 4)
			{
				matriz[3][j] = 3;
				matriz[1][j] = 1;
			}
		}


		//VERIFY 2, 2 AND 4 TO GET THE 1 AND 3 LEFT 
		for(int j=1; j<=5;j++)
		{
			if(matriz[j][0] == 2 && matriz[j][1] == 2 && matriz[j][3] == 4)
			{
				matriz[j][2] = 1;
				matriz[j][4] = 3;
			}
		}

		//VERIFY 2, 2 AND 4 TO GET THE 1 AND 3 RIGTH 
		for(int j=1; j<=5;j++)
		{
			if(matriz[j][5] == 2 && matriz[j][4] == 2 && matriz[j][2] == 4)
			{
				matriz[j][3] = 1;
				matriz[j][1] = 3;
			}
		}

		//VERIFY 2, 2 AND 4 TO GET THE 1 AND 3 DOWN 
		for(int j=1; j<=5;j++)
		{
			if(matriz[5][j] == 2 && matriz[4][j] == 2 && matriz[2][j] == 4)
			{
				matriz[3][j] = 1;
				matriz[1][j] = 3;
			}
		}

		//VERIFY 2, 2 AND 4 TO GET THE 1 AND 3 UP 
		for(int j=1; j<=5;j++)
		{
			if(matriz[0][j] == 2 && matriz[1][j] == 2 && matriz[3][j] == 4)
			{
				matriz[2][j] = 1;
				matriz[4][j] = 3;
			}
		}




		//VERIFY 2, 2 AND 4 TO GET THE 1 AND 3 DOWN 
		for(int j=1; j<=5;j++)
		{
			if(matriz[5][j] == 2 && matriz[3][j] == 2 && matriz[1][j] == 4)
			{
				matriz[2][j] = 1;
				matriz[4][j] = 3;
			}
		}

		

	for(int i=0; i<6;i++)//column
	{
            for(int j=0; j<6;j++)// line
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
	}
}