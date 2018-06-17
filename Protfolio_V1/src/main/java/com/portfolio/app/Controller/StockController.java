package com.portfolio.app.Controller;

import java.util.List;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.RequestMapping;

import com.portfolio.app.Dao.CmmnDao;
import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Structure;

@Controller
public class StockController {
	private static final Logger logger = LoggerFactory.getLogger(StockController.class);

	@Autowired
	private CmmnDao dao;
	
	public interface JnaNamuh extends Library{
		JnaNamuh INSTANCE = (JnaNamuh)Native.loadLibrary("./openapi.nm/bin/wmca.dll", JnaNamuh.class);
		
//		void wmcaAttach(HWND hWnd, char szBCType, char szInput, int nCodeLen, int nInputLen);	// 

//-입력값
//HWND hWnd		:실시간 데이터를 수신할 윈도우 핸들값입니다. 여러 윈도우를 사용할 경우 각 윈도우 핸들값으로 호출하면 개별 윈도우로 모두 전달됩니다.
//char* szBCType		:실시간 서비스 코드(BC)입니다. 원하는 서비스(실시간 시세)에 대한 식별 코드 2자리를 입력합니다. (서비스 코드는 별도 안내됨)
//			예) ‘j8’(주식체결가), ‘h1’(주식호가), …
//char* szInput		:해당 서비스가 요구하는 입력값입니다. 입력값이 여러 개일 경우 구분자없이 연속으로 입력합니다.
//예) 3개 종목(SK하이닉스,NH투자증권,삼성증권)에 대한 종목코드를 입력하는 경우, ‘000660005940005930’
//int nCodeLen		:입력값 개별 길이입니다. (byte 단위)	예) 주식종목코드를 요구할 경우 종목코드 개별길이는 6자리이므로 ‘6’을 입력합니다.
//int nInputLen		:입력값 전체 길이입니다. (byte 단위)	예) 주식종목 10개를 입력할 경우 6자리x10종목=60 자리이므로 ‘60’을 입력합니다.
//
//-반환 메시지	<구체적인 방식은 예제참조>
//CA_RECEIVESISE		:실시간 데이터 수신

		
		
		
		void wmcaConnect();		// 연결
		void wmcaDisconnect(); 	// 연결 해제


	}
	
	@RequestMapping(value = "/s0010/s0010L.do")
	public String cryptoCurrency(ModelMap model, HttpServletRequest request, 
			HttpServletResponse response, HttpSession session) throws Exception{
		
		JnaNamuh.INSTANCE.wmcaConnect();
		
		
		return "s0010/s0010L";
	}
}
