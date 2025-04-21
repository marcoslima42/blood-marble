#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ofstream img("imagem.ppm");

    if (!img.is_open()) {
        std::cerr << "Erro ao criar o arquivo.\n";
        return 1;
    }

    // Cabeçalho do PPM (formato P3)
    img << "P3\n";
    img << "3 2\n";         // largura 3, altura 2
    img << "255\n";         // valor máximo de cor

    // Pixels linha por linha (ordem RGB)
    std::vector<std::vector<int>> pixels = {
        {255, 0, 0},   {0, 255, 0},   {0, 0, 255},     // linha 1
        {255, 255, 0}, {255, 255, 255}, {0, 0, 0}      // linha 2
    };

    for (const auto& pixel : pixels) {
        img << pixel[0] << " " << pixel[1] << " " << pixel[2] << "\n";
    }

    img.close();
    std::cout << "Arquivo 'imagem.ppm' criado com sucesso!\n";
    return 0;
}
