# BrainExp2: Geant4 & ROOT Example – Linear Accelerator for Brain

**BrainExp2** is an updated Geant4 (v11+) and ROOT (v6.30+) simulation based on the example from the book [Radiación y Materia: Geant4 Hands On](https://doctoradoingenieria.udistrital.edu.co/wp-content/uploads/2023/08/6-RADIACION_MATERIA-GEANT4_HANDS_ON.pdf).  
It models a simplified linear accelerator (AL) focused on a water volume representing brain tissue.

## Objective

- Simulate a linear accelerator emitting gamma photons (~1.25 MeV) towards a water block (brain tissue).
- Accumulate and store deposited energy in a ROOT file (`output.root`).
- Visualize the geometry and events using OpenGL and the macro `vis_BrainExp.mac`.
- Analyze the energy deposition histogram (`Edep`) with ROOT.

## Project Structure

```
BrainExp2/
 ├── AcLinealCerebro.cc         # Main program (entry point)
 ├── CMakeLists.txt             # CMake configuration (Geant4 + ROOT)
 ├── include/
 │    ├── AcLinealConstruccion.hh   # Geometry: world (air) & water block
 │    ├── AcLinealFuente.hh         # Primary source: gamma rays
 │    ├── AcLinealListaFisica.hh    # Physics list: FTFP_BERT
 │    ├── RunAction.hh              # Run management
 │    ├── EventAction.hh            # Event-level energy accumulation
 │    ├── SteppingAction.hh         # Step-level energy accumulation
 │    └── HistoManager.hh           # ROOT histogram management
 ├── src/
 │    ├── AcLinealConstruccion.cc
 │    ├── AcLinealFuente.cc
 │    ├── AcLinealListaFisica.cc
 │    ├── RunAction.cc
 │    ├── EventAction.cc
 │    ├── SteppingAction.cc
 │    └── HistoManager.cc
 └── vis_BrainExp.mac           # Visualization macro
```

## Technical Requirements

- **Geant4 11+** (with `ui_all`, `vis_all`)
- **ROOT 6.30+** (for analysis and histogramming)
- **CMake ≥ 3.16**
- **C++17**
- Uses `G4NistManager` for standard materials (air, water)
- Physics list: `FTFP_BERT`

## How to Build & Run

1. **Clone the repository:**
   ```bash
   git clone https://github.com/<your-username>/BrainExp2.git
   cd BrainExp2
   ```

2. **Set up Geant4 and ROOT environments:**
   ```bash
   source /path/to/geant4.sh
   source /path/to/thisroot.sh
   ```

3. **Build the project:**
   ```bash
   mkdir build && cd build
   cmake ..
   make -j4
   ```

4. **Run the simulation with visualization:**
   ```bash
   ./BrainExp2 vis_BrainExp.mac
   ```

## Usage

- Edit macro files (e.g., `vis_BrainExp.mac`) to control simulation and visualization.
- Output is stored in `output.root` for analysis with ROOT.

## Reference

This project is an educational example adapted from  
[Radiación y Materia: Geant4 Hands On](https://doctoradoingenieria.udistrital.edu.co/wp-content/uploads/2023/08/6-RADIACION_MATERIA-GEANT4_HANDS_ON.pdf).

---

**Contact:**  
For questions or contributions, please open an