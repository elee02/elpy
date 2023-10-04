int main()
{
	Triangle t1{ 10.5, 4.5 };
	const Triangle t2{ 7.0, 3.0 };

	std::cout << "Triangle t1{ 10.5, 4.5 }" << std::endl;
	std::cout << "  base: " << t1.getBase() << std::endl;
	std::cout << "  height: " << t1.getHeight() << std::endl;
	std::cout << "  area: " << t1.area() << std::endl << std::endl;

	std::cout << "const Triangle t2{ 7.0, 3.0 }" << std::endl;
	std::cout << "  base: " << t2.getBase() << std::endl;
	std::cout << "  height: " << t2.getHeight() << std::endl;
	std::cout << "  area: " << t2.area() << std::endl << std::endl;

	return 0;
}