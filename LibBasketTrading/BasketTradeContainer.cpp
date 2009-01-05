#include "StdAfx.h"
#include "BasketTradeContainer.h"
#include "Log.h"

// need DataProvider, ExecutionProvider
// Trades data
// Need market orders

// Need DataProvider: trades data
// Need ExecutionProvider: market order, execution report, execution summary

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CBasketTradeContainer::CBasketTradeContainer( CProviderInterface *pDataProvider, CProviderInterface *pExecutionProvider ) 
: m_pDataProvider( pDataProvider ), m_pExecutionProvider( pExecutionProvider ),
  m_pVuPosition( NULL ), m_pVuSymbols( NULL ), m_pVuDialog( NULL ), m_pController( NULL )
{
  m_pModel = new CBasketTradeModel( pDataProvider, pExecutionProvider );
  m_pVuDialog = new CBasketTradeViewDialog( m_pModel );
  m_pVuDialog->ShowWindow( SW_SHOWNORMAL );
  m_pController = new CBasketTradeController( );
  LOG << "Basket Waiting";
}

CBasketTradeContainer::~CBasketTradeContainer(void) {
  if ( NULL != m_pController ) {
    delete m_pController;
    m_pController = NULL;
  }
  if ( NULL != m_pVuDialog ) {
    delete m_pVuDialog;
    m_pVuDialog = NULL;
  }
  if ( NULL != m_pModel ) {
    delete m_pModel;
    m_pModel = NULL;
  }
}

void CBasketTradeContainer::AddSymbol( const std::string &sSymbolName, const std::string &sPath, const std::string &sStrategy) {
  assert( NULL != m_pModel );
  m_pModel->AddSymbol( sSymbolName, sPath, sStrategy );
}