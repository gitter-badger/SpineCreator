/***************************************************************************
**                                                                        **
**  This file is part of SpineCreator, an easy to use, GUI for            **
**  describing spiking neural network models.                             **
**  Copyright (C) 2013 Alex Cope, Paul Richmond                           **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author: Alex Cope                                            **
**  Website/Contact: http://bimpa.group.shef.ac.uk/                       **
****************************************************************************/

#ifndef POPULATION_H
#define POPULATION_H

#include "globalHeader.h"

#include "rootdata.h"
#include "nineml_layout_classes.h"
#include "genericinput.h"
#include "projections.h"
#include "systemobject.h"


#define LOWER 0
#define UPPER 1

class population : public systemObject
{
public:
    population(float x, float y, float size, float aspect_ratio, QString name = "New population");
    population(population * data);
    population(QDomElement &e, QDomDocument * doc, QDomDocument *meta, projectObject *data);
    ~population();
    NineMLComponentData *neuronType;
    NineMLLayoutData *layoutType;
    bool within_bounds(float x, float y);
    bool is_clicked(float, float, float );
    void animate();
    void draw(QPainter *painter, float GLscale, float viewX, float viewY, int width, int height, QImage image, drawStyle style);
    void drawSynapses(QPainter *painter, float GLscale, float viewX, float viewY, int width, int height, drawStyle style);
    void drawInputs(QPainter *painter, float GLscale, float viewX, float viewY, int width, int height, drawStyle style);
    float leftBound(float pos = 0);
    float rightBound(float pos = 0);
    float topBound(float pos = 0);
    float bottomBound(float pos = 0);
    void move(float, float);
    QString name;
    QString getName();
    QString neuronTypeName;
    int numNeurons;
    QString layoutName;
    vector < projection *> projections;
    vector < projection *> reverseProjections;
    float getLeft();
    float getRight();
    float getTop();
    float getBottom();
    float getSide(int, int);
    void write_prototype_xml(QDomElement &root, QDomDocument &doc);
    void write_population_xml(QXmlStreamWriter &);
    void write_model_meta_xml(QDomDocument &meta, QDomElement &root);
    void load_projections_from_xml(QDomElement  &e, QDomDocument * doc, QDomDocument * meta, projectObject *data);
    void read_inputs_from_xml(QDomElement  &e, QDomDocument *meta, projectObject *data);
    QPainterPath * addToPath(QPainterPath * path);
    bool connectsTo(population * pop);
    void remove(rootData *data);
    void delAll(rootData *data);
    void delAll(projectObject *);
    QPointF currentLocation();
    void getNeuronLocations(vector<loc> *locations,QColor * cols);
    void print();
    void setupBounds();
    void makeSpikeSource();

    QColor colour;

//private:
    float x;
    float y;
    float targx;
    float targy;
    float animspeed;
    float left;
    float right;
    float top;
    float bottom;
    float size;
    float aspect_ratio;
    bool isVisualised;
    loc loc3;

    bool isSpikeSource;

private:

    trans tempTrans;
    void setupTrans(float GLscale, float viewX, float viewY, int width, int height);
    QPointF transformPoint(QPointF point);
};

#endif // POPULATION_H
