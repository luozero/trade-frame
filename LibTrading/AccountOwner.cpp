/************************************************************************
 * Copyright(c) 2010, One Unified. All rights reserved.                 *
 *                                                                      *
 * This file is provided as is WITHOUT ANY WARRANTY                     *
 *  without even the implied warranty of                                *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                *
 *                                                                      *
 * This software may not be used nor distributed without proper license *
 * agreement.                                                           *
 *                                                                      *
 * See the file LICENSE.txt for redistribution information.             *
 ************************************************************************/

#include "StdAfx.h"

#include <stdexcept>

#include "AccountOwner.h"

namespace ou { // One Unified
namespace tf { // TradeFrame

const std::string CAccountOwner::m_sTableName = "accountowners";

CAccountOwner::CAccountOwner( 
    const keyAccountOwnerId_t& sAccountOwnerId, 
    const keyAccountAdvisorId_t& sAccountAdvisorId,
    const std::string& sFirstName, const std::string& sLastName ) 
: m_row( sAccountOwnerId, sAccountAdvisorId, sFirstName, sLastName )
{
}

CAccountOwner::CAccountOwner( const TableRowDef& row ) : m_row( row ) {};

CAccountOwner::~CAccountOwner(void) {
}

} // namespace tf
} // namespace ou