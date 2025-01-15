#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cstdint>

#define X 180
#define Y 90 

struct Point
{
    double x0;
    double y0;
    double x1;
    double y1;
};

double GenerateRandomNumber();

double GenerateRandomNumber(uint8_t bounds)
{
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_real_distribution<double> dis(-bounds, bounds);
    return dis(gen);
}

void GenerateJsonFile(std::string_view filename, std::vector<Point> points)
{
    std::ofstream file(filename.data());
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    file << "{\n";
    file << "  \"points\": [\n";
    for (size_t i = 0; i < points.size(); i++)
    {
        file << "    {\n";
        file << "      \"x0\": " << points[i].x0 << ",\n";
        file << "      \"y0\": " << points[i].y0 << ",\n";
        file << "      \"x1\": " << points[i].x1 << ",\n";
        file << "      \"y1\": " << points[i].y1 << "\n";
        file << "    }";
        if (i < points.size() - 1)
        {
            file << ",";
        }
        file << "\n";
    }
    file << "  ]\n";
    file << "}\n";
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <num_points>" << std::endl;
        return 1;
    }
    uint64_t num_points = std::stoull(argv[1]);
    
    auto points = std::vector<Point>();
    points.reserve(num_points);
    for(uint64_t i = 0; i < num_points; i++)
    {
        points.emplace_back(GenerateRandomNumber(X), GenerateRandomNumber(Y), GenerateRandomNumber(X), GenerateRandomNumber(Y));
        std::cout << "Point " << i << ": (" << points[i].x0 << ", " << points[i].y0 << ") -> (" << points[i].x1 << ", " << points[i].y1 << ")" << std::endl;

    }

    GenerateJsonFile("points.json", points);

    return 0;
}