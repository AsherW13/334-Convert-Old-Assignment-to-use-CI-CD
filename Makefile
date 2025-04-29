all:
	g++ -g -std=c++11 main.cpp bst.cpp -o treeTester.out
	./treeTester.out

deb:
	rm -rf deb-build
	mkdir -p deb-build/DEBIAN
	mkdir -p deb-build/usr/local/bin

	cp treeTester.out deb-build/usr/local/bin/tree-tester

	echo "Package: tree-tester" > deb-build/DEBIAN/control
	echo "Version: 1.0" >> deb-build/DEBIAN/control
	echo "Maintainer:  ME" >> deb-build/DEBIAN/control
	echo "Description: " >> deb-build/DEBIAN/control

	dpkg-deb --build deb-build
	mv deb-build.deb tree-tester_1.0_amd64.deb