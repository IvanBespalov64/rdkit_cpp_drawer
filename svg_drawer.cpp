#include <GraphMol/GraphMol.h>
#include <GraphMol/SmilesParse/SmilesParse.h>
#include <GraphMol/Depictor/RDDepictor.h>
#include <GraphMol/MolDraw2D/MolDraw2DSVG.h>

#include <string>
#include <iostream>

std::string generateSVGfromSmiles(
    std::string& smiles,
    int width = 300,
    int height = 300
) {

    RDKit::ROMol *mol = RDKit::SmilesToMol(smiles);
        
    if (!mol)
        return "";

    RDDepict::compute2DCoords(*mol);

    RDKit::MolDraw2DSVG strDrawer(width, height);
    strDrawer.drawMolecule(*mol);
    strDrawer.finishDrawing();
    std::string svg = strDrawer.getDrawingText();

    delete mol;
    return svg;

}

int main() {
    
    std::string smiles("c1ccccc1");
    std::cout << generateSVGfromSmiles(smiles);

    return 0;
}
