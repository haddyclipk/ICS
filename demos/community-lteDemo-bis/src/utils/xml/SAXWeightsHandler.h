/****************************************************************************/
/// @file    SAXWeightsHandler.h
/// @author  Daniel Krajzewicz
/// @date    Fri, 30 Mar 2007
/// @version $Id: SAXWeightsHandler.h 8719 2010-05-04 12:15:47Z behrisch $
///
// An XML-handler for network weights
/****************************************************************************/
// SUMO, Simulation of Urban MObility; see http://sumo.sourceforge.net/
// Copyright 2001-2010 DLR (http://www.dlr.de/) and contributors
/****************************************************************************/
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
//
/****************************************************************************/
#ifndef SAXWeightsHandler_h
#define SAXWeightsHandler_h


// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

#include <string>
#include <utils/xml/SUMOSAXHandler.h>
#include <utils/common/SUMOTime.h>


// ===========================================================================
// class declarations
// ===========================================================================
class OptionsCont;
class RONet;
class ROEdge;


// ===========================================================================
// class definitions
// ===========================================================================
/**
 * @class SAXWeightsHandler
 * @brief An XML-handler for network weights
 *
 * As network weights are used both in the simulation and the routers, a base
 *  class for loading them was built. Instances of this class should be supplied
 *  with at least one definition about what shall be retrieved
 *  (ToRetrieveDefinition, defined as inner class) which also contains the information
 *  about the retriever (EdgeFloatTimeLineRetriever, defined as inner class).
 *
 * The ToRetrieveDefinition names the attribute which the SAXWeightsHandler shall
 *  parse and reporte. Within the parsed xml-file these attributes may be embedded
 *  in "lane" or "edge" elements, one for each edge or for each lane (see below).
 *  These elements should be embedded in interval-tags which specify the time the
 *  weight is valid at.
 *  The boolean "edgeBased" tells SAXWeightsHandler whether the weights are supplied
 *  on edge- or on lane-basis (whether it shall parse the "edge" or the "lane" elements).
 *
 * Examples for files the SAXWeightsHandler can handle are the edgedump and the lanedump
 *  generated by the simulation.
 *
 * The EdgeFloatTimeLineRetriever to which read values will be reported should have the
 *  method "addEdgeWeight" implemented. It wil be supplied with the current edge name,
 *  the interval the weight is valid for and the value.
 */
class SAXWeightsHandler : public SUMOSAXHandler
{
public:
    /**
     * @class EdgeFloatTimeLineRetriever
     * @brief Interface for a class which obtains read weights for named edges
     */
    class EdgeFloatTimeLineRetriever
    {
    public:
        /// @brief Constructor
        EdgeFloatTimeLineRetriever() throw() { }

        /// @brief Destructor
        virtual ~EdgeFloatTimeLineRetriever() throw() { }

        /** @brief Adds a weight for a given edge and time period
         *
         * @param[in] id The id of the object to add a weight for
         * @param[in] val The weight
         * @param[in] beg The begin of the interval the weight is valid for
         * @param[in] end The end of the interval the weight is valid for
         */
        virtual void addEdgeWeight(const std::string &id,
                                   SUMOReal val, SUMOReal beg, SUMOReal end) const throw() = 0;

    };

    /**
     * @class ToRetrieveDefinition
     * @brief Complete definition about what shall be retrieved and where to store it
     */
    class ToRetrieveDefinition
    {
    public:
        /// Constructor
        ToRetrieveDefinition(const std::string &attributeName, bool edgeBased,
                             EdgeFloatTimeLineRetriever &destination);

        /// Destructor
        ~ToRetrieveDefinition();

    public:
        /// The attribute name that shall be parsed
        std::string myAttributeName;

        /// The class that shall be called when new data is avaiable
        EdgeFloatTimeLineRetriever &myDestination;

        /// Information whether edge values shall be used (lane value if false)
        bool myAmEdgeBased;

        /// aggregated value over the lanes read within the current edge
        SUMOReal myAggValue;

        /// The number of lanes read for the current edge
        size_t myNoLanes;

        /// Information whether the attribute has been found for the current edge
        bool myHadAttribute;

    private:
        /// @brief Invalidated copy constructor.
        ToRetrieveDefinition(const ToRetrieveDefinition&);

        /// @brief Invalidated assignment operator.
        ToRetrieveDefinition& operator=(const ToRetrieveDefinition&);

    };

    /**
     * @brief Constructor
     *
     * Gets a list of retriever definitions. Please note that the retrievers are
     *  not deleted!
     */
    SAXWeightsHandler(const std::vector<ToRetrieveDefinition*> &defs,
                      const std::string &file);


    /**
     * @brief Constructor
     *
     * Gets a single definition. Please note that the retrievers are not deleted!
     */
    SAXWeightsHandler(ToRetrieveDefinition *def,
                      const std::string &file);


    /// Destructor
    ~SAXWeightsHandler() throw();


protected:
    /// @name inherited from GenericSAXHandler
    //@{

    /** @brief Called on the opening of a tag;
     *
     * @param[in] element ID of the currently opened element
     * @param[in] attrs Attributes within the currently opened element
     * @exception ProcessError If something fails
     * @see GenericSAXHandler::myStartElement
     */
    void myStartElement(SumoXMLTag element,
                        const SUMOSAXAttributes &attrs) throw(ProcessError);


    /** @brief Called when a closing tag occurs
     *
     * @param[in] element ID of the currently opened element
     * @exception ProcessError If something fails
     * @see GenericSAXHandler::myEndElement
     */
    void myEndElement(SumoXMLTag elemente) throw();
    //@}


private:
    /// Parses the efforts of a lane for the previously read times
    void tryParse(const SUMOSAXAttributes &attrs, bool isEdge);


private:
    /// List of definitions what shall be read and whereto stored while parsing the file
    std::vector<ToRetrieveDefinition*> myDefinitions;

    /// the begin of the time period that is currently processed
    SUMOReal myCurrentTimeBeg;

    /// the end of the time period that is currently processed
    SUMOReal myCurrentTimeEnd;

    /// the edge which is currently being processed
    std::string myCurrentEdgeID;


private:
    /// we made the copy constructor invalid
    SAXWeightsHandler(const SAXWeightsHandler &src);

    /// we made the assignment operator invalid
    SAXWeightsHandler &operator=(const SAXWeightsHandler &src);

};


#endif

/****************************************************************************/

