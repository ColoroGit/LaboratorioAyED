namespace labsemana1_ejercicio7.Ex07.models
{
    public class Vehiculo
    {
        public string fabricante {get; set;} = string.Empty;
        public string modelo {get; set;} = string.Empty;
        public int año {get; set;}
        public int percentVelocidad {get; set;}
        public int percentManiobrabilidad {get; set;}

        public Vehiculo()
        {

        }
        public Vehiculo(string fabricante, string modelo, int año, int percentVelocidad, int percentManiobrabilidad)
        {
            this.fabricante = fabricante;
            this.modelo = modelo;
            this.año = año;
            this.percentVelocidad = percentVelocidad;
            this.percentManiobrabilidad = percentManiobrabilidad;
        }

        public string MostrarDatos()
        {
            return "\nFabricante: " + this.fabricante + "\nModelo: " + this.modelo + "\nAño: " + this.año + "\nPorcentaje de Velocidad: " + this.percentVelocidad + "%" + "\nPorcentaje de Maniobrabilidad: " + this.percentManiobrabilidad + "%";
        }
    }
}