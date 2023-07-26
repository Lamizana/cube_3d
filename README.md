# cube_3d
1ere etape parsing

extension .cub

faire un index pour avoir les types d'element avant de parser la carte 


pour la carte elle-meme juste 6 char 0, 1, N ,E, W , S

verifier les murs 


F 220,100,0 NO ./path_to_the_north_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
C 225,30,0
SO ./path_to_the_south_texture

11111
10001
1111

11111111
10001111
10 011111
 110001101
111111111


struc textur{
	char fd[];
	char *NO
	char *SO
	char *WE
	char *EA

	int C[255, 255, 255]
	int F[255, 255, 255]
}

struct map{
	char **map;
	
}


struct point
{
	int	 x;
	int	 y;
	int	 z;
	char descriptor;
}
