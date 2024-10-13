# taller1SOFIACONTRERAS
integrante:

Sofia Catalina Contreras Godoy
Rut: 21.702.328-9 
Correo institucional: sofia.contreras02@alumnos.ucn.cl

Compilacion:
$g++ -I./include source/Libro.cpp source/MaterialBibliografico.cpp source/Revista.cpp source/Usuario.cpp source/main.cpp -o simuladorBiblioteca

Ejecucion: ./simuladorBiblioteca

Descripcion de las clases en el main:
MaterialBibliografico a traves de leer Biblioteca.txt, crea los siguientes objetos:

Libro1/hereda de materialBibliografico: { nombre:”El Quijote”; ISBN: ”978-3-16-148410-0”; Autor:”Miguel de Cervantes”; Año:”1605”; Resumen:Aventuras de un hidalgo llamado Don Quijote}
Libro2/hereda de materialBibliografico: { nombre:”Cien Años de Soledad”; ISBN: ”978-0-14-118499-9”; Autor:”Gabriel Garcia Marquez”; Año:”1967”; Resumen:Una familia atrapada en el tiempo}
Revista1/hereda de materialBibliografico: {nombre: Nature; ISBN: 0028-0836;Autor: John Smith;numeroEdicion:505; mesPublicacion:Mayo}
Revista2/hereda de materialBibliografico: { nombre: Scientific American; ISBN: 0036-8733;autor:Jane Doe;numeroEdicion: 1001; mesPublicacion: Junio}

Luego se crean las clases de Usuario a traves de Usuarios.txt

Usuario1: {nombre: Juan Perez ; ID:1 }
Usuario2: {nombre: Maria Gomez ; ID:2 }
Usuario3: {nombre: Carlos Sanchez; ID:3 }

