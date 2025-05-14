#include <iostream>
#include <vector>
#include <algorithm>
#include "Vehicle.hpp"
#include <locale.h> 

using namespace std;

Vehicle* FindVehicle(vector<Vehicle>& vehicles, string plate) {
    for (auto& vehicle : vehicles) {
        if (vehicle.GetPlate() == plate) {
            return &vehicle;
        }
    }
    return nullptr;
}

void ListVehicles(vector<Vehicle>& vehicles) {
    cout << "\n== Veículos Cadastrados ==" << endl;
    for (size_t i = 0; i < vehicles.size(); i++) {
        cout << i << " - Placa: " << vehicles[i].GetPlate() << endl;
    }
}

int main() {

    setlocale(LC_ALL, "pt_BR.UTF-8");
    vector<Vehicle> vehicles;
    int option;

    do {
        cout << "\n=====  Trabalho I- Programação II UFSC =====\n";
        cout << "ESCOLHA UMA DAS OPÇÕES ABAIXO: \n";
        cout << "1. Cadastrar Veículo\n";
        cout << "2. Remover Veículo\n";
        cout << "3. Adicionar uma Rota a um Veículo\n";
        cout << "4. Remover uma Rota de um Veículo\n";
        cout << "5. Relatório por Veículo (listar rotas)\n";
        cout << "6. Relatório Geral (listar veículos e quilometragem total)\n";
        cout << "7. Pesquisar por substring (origem/destino)\n";
        cout << "0. Sair\n";
        cout << "Selecione uma opção: ";
        cin >> option;
        cin.ignore();

        switch (option) {
            case 1: {
                string plate, model, brand;
                cout << "Informe a placa: ";
                getline(cin, plate);
                cout << "Informe o modelo: ";
                getline(cin, model);
                cout << "Informe a marca: ";
                getline(cin, brand);
                vehicles.push_back(Vehicle(plate, model, brand, 0.0f));
                cout << "Veículo cadastrado com sucesso!" << endl;
                break;
            }
            case 2: {
                string plate;
                cout << "Informe a placa do veículo que deseja remover: ";
                getline(cin, plate);
                auto it = remove_if(vehicles.begin(), vehicles.end(),
                    [plate](Vehicle& v) { return v.GetPlate() == plate; });
                if (it != vehicles.end()) {
                    vehicles.erase(it, vehicles.end());
                    cout << "Veículo removido!" << endl;
                } else {
                    cout << "Veículo não encontrado!" << endl;
                }
                break;
            }
            case 3: {
                string plate, origin, destination;
                float distance;
                cout << "Informe a placa do veículo: ";
                getline(cin, plate);
                Vehicle* vehicle = FindVehicle(vehicles, plate);
                if (vehicle) {
                    cout << "Informe a cidade de origem: ";
                    getline(cin, origin);
                    cout << "Informe a cidade de destino: ";
                    getline(cin, destination);
                    cout << "Informe a distância em km: ";
                    cin >> distance;
                    cin.ignore();
                    vehicle->IncludeTrip(origin, destination, distance);
                    cout << "Rota adicionada!" << endl;
                } else {
                    cout << "Veículo não encontrado!" << endl;
                }
                break;
            }
            case 4: {
                string plate;
                size_t index;
                cout << "Informe a placa do veículo: ";
                getline(cin, plate);
                Vehicle* vehicle = FindVehicle(vehicles, plate);
                if (vehicle) {
                    cout << "Rotas disponíveis:\n";
                    cout << vehicle->GetAllTrips();
                    cout << "Informe o índice da rota para remover: ";
                    cin >> index;
                    cin.ignore();
                    if (vehicle->RemoveTrip(index)) {
                        cout << "Rota removida com sucesso!" << endl;
                    } else {
                        cout << "Índice inválido!" << endl;
                    }
                } else {
                    cout << "Veículo não encontrado!" << endl;
                }
                break;
            }
            case 5: {
                string plate;
                cout << "Informe a placa do veículo: ";
                getline(cin, plate);
                Vehicle* vehicle = FindVehicle(vehicles, plate);
                if (vehicle) {
                    cout << "Rotas do veículo:\n";
                    cout << vehicle->GetAllTrips();
                } else {
                    cout << "Veículo não encontrado!" << endl;
                }
                break;
            }
            case 6: {
                cout << "\n== Relatório Geral ==\n";
                for (auto& vehicle : vehicles) {
                    cout << "Placa: " << vehicle.GetPlate()
                         << " | Quilometragem total: " << vehicle.GetTotalKm() << " km\n";
                }
                break;
            }
            case 7: {
                string word;
                cout << "Informe uma palavra para buscar: ";
                getline(cin, word);
                bool found = false;
                for (auto& vehicle : vehicles) {
                    string result = vehicle.SearchTripBySubstring(word);
                    if (!result.empty()) {
                        cout << "\nVeículo placa " << vehicle.GetPlate() << ":\n";
                        cout << result;
                        found = true;
                    }
                }
                if (!found) {
                    cout << "Nenhuma rota encontrada com essa substring!" << endl;
                }
                break;
            }
            case 0:
                cout << "Muito Obrigado, até breve!" << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente!" << endl;
        }
    } while (option != 0);

    return 0;
}
