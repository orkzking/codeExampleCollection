#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" @mainpage The script shows that both dummy implementations generate the same output

    And it is ensured that only if this script is executed the code is running

    Also this is an example how to check the old and new syntax in one file

    The whole template is based on the following tutorial see there for further reading:
    https://www.python-course.eu/python3_abstract_classes.php
"""
import sys

sys.path.append("../")

if __name__ == "__main__":
    import geo_tree_dep.Quadrat as gtdQuadrat
    import geo_tree_dep.Kreis as gtdKreis
    import geo_tree_dep.Dreieck as gtdDreieck
    import geo_lin_dep.Quadrat as ltdQuadrat
    import geo_lin_dep.Kreis as ltdKreis
    import geo_lin_dep.Dreieck as ltdDreieck
    import geo_tree_dep.D3.Quader as gtdQuader

    print("Starting with the linear dependencies\n")
    old_syntax_list = list()  # [ltdQuadrat.Quadrat(), ltdKreis.Kreis(), ltdDreieck.Dreieck()]
    old_syntax_list.append(ltdQuadrat.Quadrat([0.0,0.0],[1.0,0.0],[1.0,1.0],[0.1,1.0]))
    old_syntax_list.append(ltdKreis.Kreis([0.0, 0.0],2.0))
    old_syntax_list.append(ltdDreieck.Dreieck( [0.0, 0.0], [0.0, 3.0], [1.5, 2.5981]))
    for polygon in old_syntax_list:
        polygon.printMyData()
    print("Finished linear dependencies")

    print("Starting with the tree dependencies\n")
    new_syntax_list = [gtdQuadrat.Quadrat(), gtdKreis.Kreis(), gtdDreieck.Dreieck(), gtdQuader.Quader()]
    for polygon in new_syntax_list:
        polygon.printMyData()
    print("Finished")
