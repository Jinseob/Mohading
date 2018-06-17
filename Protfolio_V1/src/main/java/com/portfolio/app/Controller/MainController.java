package com.portfolio.app.Controller;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import com.portfolio.app.Dao.CmmnDao;
import com.portfolio.app.Model.DC0010VO;
import com.portfolio.app.Model.LSM0010VO;
import com.portfolio.app.Model.SearchOptionVO;

@Controller
public class MainController {
	private static final Logger logger = LoggerFactory.getLogger(MainController.class);

	@Autowired
	private CmmnDao dao;
	
	@RequestMapping(value = "/main.do")
	public String main(Locale locale, ModelMap model, RedirectAttributes redirectAttr,
			HttpServletRequest request, HttpServletResponse response, HttpSession session) throws Exception{
		
		SearchOptionVO searchOptionVO = new SearchOptionVO();
		@SuppressWarnings("unchecked")
		List<LSM0010VO> list = (List<LSM0010VO>) dao.selectList("common.select_LSM0010", searchOptionVO);
		model.addAttribute("list", list);
		
		return "main";
	}
	
	@RequestMapping(value = "/Link/{procType}.do")
	public String link(@PathVariable String procType, Locale locale, ModelMap model, RedirectAttributes redirectAttr,
			HttpServletRequest request, HttpServletResponse response, HttpSession session) throws Exception{
		
		System.out.println(procType);
		
		// 키워드 트렌드 수치 분석 부분
		if(procType.equals("KEYWORD")) {
			String clientId = "KT16SCpqCpu8Q15nBQLr";
			String clientSecret = "KLSZZf4wkx";
			
			try {
	            String apiURL = "https://openapi.naver.com/v1/datalab/search";
	            String body = "{\"startDate\":\"2017-01-01\",\"endDate\":\"2017-04-30\",\"timeUnit\":\"month\",\"keywordGroups\":[{\"groupName\":\"금융\",\"keywords\":[\"금융\",\"korean\"]},{\"groupName\":\"영어\",\"keywords\":[\"영어\",\"english\"]}],\"device\":\"pc\",\"ages\":[\"1\",\"2\"],\"gender\":\"f\"}";
	            URL url = new URL(apiURL);
	            HttpURLConnection con = (HttpURLConnection)url.openConnection();
	            con.setRequestMethod("POST");
	            con.setRequestProperty("X-Naver-Client-Id", clientId);
	            con.setRequestProperty("X-Naver-Client-Secret", clientSecret);
	            con.setRequestProperty("Content-Type", "application/json");

	            con.setDoOutput(true);
	            DataOutputStream wr = new DataOutputStream(con.getOutputStream());
	            wr.write(body.getBytes());
	            wr.flush();
	            wr.close();

	            int responseCode = con.getResponseCode();
	            BufferedReader br;
	            if(responseCode==200) { // 정상 호출
	                br = new BufferedReader(new InputStreamReader(con.getInputStream()));
	            } else {  // 에러 발생
	                br = new BufferedReader(new InputStreamReader(con.getErrorStream()));
	            }

	            String inputLine;
	            StringBuffer sbResponse = new StringBuffer();
	            while ((inputLine = br.readLine()) != null) {
	            	sbResponse.append(inputLine);
	            }
	            br.close();
	            System.out.println(sbResponse.toString());

	        } catch (Exception e) {
	            System.out.println(e);
	        }
		}else if(procType.equals("RANKTITLE")) {
			DataController dataController = new DataController();
			Elements elements = dataController.getRealTimeKeyword();
			
//			dataController.getKeywordForYear(dao);	// Data 수집용 테스트. 추후 스케줄러로 이동.
			
			SearchOptionVO searchOptionVO = new SearchOptionVO();
			@SuppressWarnings("unchecked")
//			List<DC0010VO> list = (List<DC0010VO>) dao.selectList("dc0010.selectKeyword", searchOptionVO);
			List<DC0010VO> list = new ArrayList<DC0010VO>();
			DC0010VO dc0010VO = null;
			for(int i = 0; i < elements.size(); i++) {
				Element element = elements.get(i);
				dc0010VO = new DC0010VO();
				dc0010VO.setKeyword(element.select("span.title").text());
				dc0010VO.setRank(element.select("em.num").text());
				list.add(dc0010VO);
			}
			
			model.addAttribute("list", list);
			
			procType = "/dc0010/dc0010L";
		}else if(procType.indexOf("_") > -1) {
			procType = "/" + procType.substring(0, procType.indexOf("_")) + "/" + procType;
		}
		
		
//		SearchOptionVO searchOptionVO = new SearchOptionVO();
//		@SuppressWarnings("unchecked")
//		List<LSM0010VO> list = (List<LSM0010VO>) dao.selectList("common.select_LSM0010", searchOptionVO);
//		model.addAttribute("list", list);
		
		return procType;
	}
}
