namespace labsemana1_ejercicio6.Ex06.models
{
    public class Jugador
    {
        public string tipo {get; set;} = string.Empty;
        public string nombre {get; set;} = string.Empty;
        public int vida {get; set;}
        public int poder {get; set;} //Interpreté la variable poder como un multiplicador del daño que puede generar un personaje, que podría depender del tipo
        public int mana {get; set;} = 100; //Esta variable extra representa los recursos que tiene el jugador para hacer hechizos, cada hechizo pide una cierta cantidad de mana para ser cargado
        public int velocidad {get; set;}
        public string hechizoCargado {get; set;} = string.Empty; 

        public Jugador()
        {

        }
        public Jugador(string tipo, string nombre, int vida, int poder, int velocidad)
        {
            this.tipo = tipo; //Eventualmente, si se desarrollase más el programa, las variables de vida, poder y velocidad dependieran de los tipos, que estarían predefinidos 
            this.nombre = nombre;
            this.vida = vida;
            this.poder = poder;
            this.velocidad = velocidad;
        }

        public void Descansar()
        {
            this.vida += 50;

            if (this.vida > 100)
            {
                this.vida = 100;
            }
        }
        public int Atacar(int dañoHechizo) //En un teorico menu de combate, al haber cargado un hechizo, te dará la opcion de atacar, y dependiendo del hechizo hará una cierta cantidad de daño
        {
            return dañoHechizo * poder; //el daño de este hechizo será aumentado proporcionalmente a la cantidad de poder
        }
        public void CargarHechizo(string hechizo, int costoHechizo)
        {
            hechizoCargado = hechizo; //el hechizo elegido será cargado a cambio de cierta cantidad de mana
            mana -= costoHechizo;
        }
        public void CargarMana(int manaExtra)
        {
            mana += manaExtra; //se recarga una cierta cantidad de mana, que podría depender del tipo
        }
    } 
}