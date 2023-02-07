def main():
    n = int(input().strip())
    faces = 0
    for i in range(n):
        polyhedron = input().strip()
        if polyhedron == "Tetrahedron":
            faces += 4
        elif polyhedron == "Cube":
            faces += 6
        elif polyhedron == "Octahedron":
            faces += 8
        elif polyhedron == "Dodecahedron":
            faces += 12
        elif polyhedron == "Icosahedron":
            faces += 20
    print(faces)

if __name__ == '__main__':
    main()
