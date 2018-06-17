package com.portfolio.app.Controller;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLEncoder;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.JSONValue;
import org.json.simple.parser.JSONParser;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.view.json.MappingJackson2JsonView;

import com.portfolio.app.Dao.CmmnDao;
import com.portfolio.app.Model.CC0010VO;
import com.portfolio.app.Model.CC0011VO;
import com.portfolio.app.Model.SearchOptionVO;

@Controller
public class JSONController {
	private static final Logger logger = LoggerFactory.getLogger(JSONController.class);

	@Autowired
	private CmmnDao dao;
		
	@RequestMapping(value = "/UpbitData.json")
	public ModelAndView upbitData(@ModelAttribute("searchOptionVO") SearchOptionVO searchOptionVO,
			ModelMap model, HttpServletRequest request, HttpServletResponse response, HttpSession session) throws Exception{
		
		final String btcusdt 	= "BTCUSDT";
		final String ethusdt 	= "ETHUSDT";
		final String ltcusdt 	= "LTCUSDT";
		final String xlmbtc 	= "XLMBTC";
		final String adabtc 	= "ADABTC";
		final String qtumbtc 	= "QTUMBTC";
		
		ModelAndView modelAndView = new ModelAndView();
		MappingJackson2JsonView jsonView = new MappingJackson2JsonView();
		modelAndView.setView(jsonView);
		
		List<CC0010VO> list = new ArrayList<CC0010VO>();
		
//		String upbitURL = "https://crix-api-endpoint.upbit.com/v1/crix/candles/minutes/1?code=CRIX.UPBIT.KRW-XLM";
		String upbitURL = "https://crix-api-endpoint.upbit.com/v1/crix/candles/minutes/1?code=CRIX.UPBIT.KRW-";
		String coinnestURL = "https://api.coinnest.co.kr/api/pub/ticker?coin=tron";
		String binanceURL = "https://api.binance.com/api/v1/ticker/price";	//symbol=BTCUSDT 추가하면 하나씩 받아올 수 있음
		
		// Binance Data 가져오는 부분.
		URL binanceUrl = new URL(binanceURL);
		HttpURLConnection binanceCon = (HttpURLConnection)binanceUrl.openConnection();
		Object binanceObj = JSONValue.parse(new InputStreamReader(binanceCon.getInputStream()));

		JSONArray binanceList = (JSONArray) binanceObj;	// array 는 그냥 Object 로 받아서 바로 넣으면 됨.
		// ----
		
		
		URL upbitUrl = null;
		HttpURLConnection upbitCon = null;
		Object upbitObj = null;
		JSONArray upbitList = null;
		JSONObject jsonObj = null;
		String symbol = "";
		String code = "";
		CC0010VO tempObj = null;
		for(int i = 0; i < binanceList.size(); i++) {
//		for(int i = 0; i < 3; i++) {
			boolean chk = false;
			JSONObject obj = (JSONObject) binanceList.get(i);
			symbol = obj.get("symbol").toString();
			
			if(symbol.equals(btcusdt) || symbol.equals(ethusdt) || symbol.equals(ltcusdt)) {
				code = symbol.substring(0, symbol.indexOf("USDT"));
				chk = true;
			}else if(symbol.equals(xlmbtc) || symbol.equals(adabtc) || symbol.equals(qtumbtc)) {
				code = symbol.substring(0, symbol.indexOf("BTC"));
				chk = true;
			}
			
			if(chk) {
				upbitUrl = new URL(upbitURL + code);
				upbitCon = (HttpURLConnection)upbitUrl.openConnection();
				upbitObj = JSONValue.parse(new InputStreamReader(upbitCon.getInputStream()));
				upbitList = new JSONArray();
				upbitList = (JSONArray) upbitObj;
				jsonObj = new JSONObject();
				jsonObj = (JSONObject) upbitList.get(0);
				tempObj = new CC0010VO();
				tempObj.setCode(jsonObj.get("code").toString());
				tempObj.setUpbitPrice(jsonObj.get("tradePrice").toString());
				tempObj.setBinancePrice(obj.get("price").toString());
				
				list.add(tempObj);
			}
		}
		
		model.addAttribute("list", list);
		
		// BTC, ADA, XLM, XRP, ETH, QTUM, STEEM, SNT, NEO, QTUM 등을 추가해서 1분에 한번씩 돌려서 새로고침되도록.
		// 실시간 또는 당일 원화 정보도 가져와야겠네
		
		
		
//		JSONObject object = (JSONObject) JSONValue.parseWithException(isr);
		
//		System.out.println(isr);
//		System.out.println("jObj : " + object.toString());

		
//		Document document = Jsoup.connect(upbitURL).get();
//		
//		System.out.println(document);
		
		return modelAndView;
	}
	
	@RequestMapping(value = "/CryptoCurrNews.json")
	public ModelAndView cryptoCurrNews(@ModelAttribute("searchOptionVO") SearchOptionVO searchOptionVO,
			ModelMap model, HttpServletRequest request, HttpServletResponse response, HttpSession session) throws Exception{
		
		
		ModelAndView modelAndView = new ModelAndView();
		MappingJackson2JsonView jsonView = new MappingJackson2JsonView();
		modelAndView.setView(jsonView);
		
//		List<CC0010VO> list = new ArrayList<CC0010VO>();
		
		final String query 	= "가상화폐 암호화폐";
		String newsURL = "https://openapi.naver.com/v1/search/news.json?query=";
		//String apiURL = "https://openapi.naver.com/v1/search/blog.xml?query="+ text; // xml 결과
		String text = URLEncoder.encode(query, "UTF-8");
		
		String clientId = "KT16SCpqCpu8Q15nBQLr";//애플리케이션 클라이언트 아이디값";
        String clientSecret = "KLSZZf4wkx";//애플리케이션 클라이언트 시크릿값";
        
        try {

        	URL newsUrl = new URL(newsURL + text);
    		HttpURLConnection newsCon = (HttpURLConnection)newsUrl.openConnection();
    		newsCon.setRequestMethod("GET");
    		newsCon.setRequestProperty("X-Naver-Client-Id", clientId);
    		newsCon.setRequestProperty("X-Naver-Client-Secret", clientSecret);
        	
            int responseCode = newsCon.getResponseCode();
            BufferedReader br;
            if(responseCode==200) { // 정상 호출
                Object newsObj = JSONValue.parse(new InputStreamReader(newsCon.getInputStream(), "utf-8"));
                
                JSONObject jsonObj = (JSONObject) newsObj;
                
                JSONArray newsList = (JSONArray) jsonObj.get("items");	// array 는 그냥 Object 로 받아서 바로 넣으면 됨.
                JSONObject tempObj = null;
                CC0011VO cc0011VO = null;
                List<CC0011VO> list = new ArrayList<CC0011VO>();
                for(int i = 0; i < newsList.size(); i++) {
                	tempObj = new JSONObject();
                	tempObj = (JSONObject) newsList.get(i);
                	cc0011VO = new CC0011VO();
                	cc0011VO.setTitle(tempObj.get("title").toString());
                	cc0011VO.setDescription(tempObj.get("description").toString());
                	cc0011VO.setLink(tempObj.get("link").toString());
                	cc0011VO.setOriginallink(tempObj.get("originallink").toString());
                	cc0011VO.setPubDate(tempObj.get("pubDate").toString());
                	
                	list.add(cc0011VO);
                }
                
                model.addAttribute("newsList", list);
            } else {  // 에러 발생
                br = new BufferedReader(new InputStreamReader(newsCon.getErrorStream()));
                String inputLine;
                StringBuffer responseSB = new StringBuffer();
                while ((inputLine = br.readLine()) != null) {
                	responseSB.append(inputLine);
                }
                br.close();
                System.out.println(responseSB.toString());
            }
        } catch (Exception e) {
            System.out.println(e);
        }
		
		return modelAndView;
	}
}
