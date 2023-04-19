namespace LabSemana3.labsemana3_ejercicio4.models
{
    public class Jugador
    {
        public string name {get; set;} = string.Empty;
        public int id {get; set;} = 0; 
        public int team {get; set;} = 0;
        public int damage {get; set;} = 0;
        public int speed {get; set;} = 0;
        public int health {get; set;} = 100;
        public int stamina {get; set;} = 500;
        public int score {get; set;} = 0;
        public bool cargando {get; set;} = false;
        public int[] movimientos = {0, 0, 0}; 

        public Jugador()
        {

        }
        public Jugador(string name, int id, int team)
        {
            Random r = new Random();
            int[] movUsed = new int[3];
            int op;
            int i = 0;
            int j;
            bool picked = false;

            this.name = name;
            this.id = id;
            this.team = team;
            this.damage = r.Next(21);
            this.speed = 20 - this.damage;

            while (i < 3)
            {
                op = r.Next(8) + 1;
                picked = false;
                
                for (j = 0; j < 3; j++)
                {
                    if (op == movUsed[j])
                    {
                        picked = true;
                        break;
                    }
                }
                    
                if (!picked)
                {
                    this.movimientos[i] = op;
                    movUsed[i] = op;
                    i++;
                }
            }
        }
        public Jugador(string name, int id, int team, int damage, int mov1, int mov2, int mov3)
        {
            this.name = name;
            this.id = id;
            this.team = team;
            this.damage = damage;
            this.speed = 20 - this.damage;
            this.movimientos[0] = mov1;
            this.movimientos[1] = mov2;
            this.movimientos[2] = mov3;
        }
    }
}