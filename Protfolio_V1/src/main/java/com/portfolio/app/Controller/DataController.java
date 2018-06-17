package com.portfolio.app.Controller;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.List;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import org.springframework.stereotype.Controller;

import com.portfolio.app.Dao.CmmnDao;
import com.portfolio.app.Model.DC0010VO;
import com.portfolio.app.Model.SearchOptionVO;

@Controller
public class DataController {
	//	특정시간마다 한번씩 실행되어서 저장됨.
	public Elements getRealTimeKeyword() throws Exception{
		Calendar today = Calendar.getInstance();
		SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		
		today.set(Calendar.SECOND, 0);	// 00, 30 초 기준으로만 데이터를 가지고 온다.
		
		String date = format.format(today.getTime()).replace(" ", "T");
		
		String url = "https://datalab.naver.com/keyword/realtimeList.naver?";
//		String datetime = "datetime=2018-01-02T14:49:00";
		String datetime = "datetime=" + date;
		Document document = Jsoup.connect(url + datetime).get();
		
		if(null != document) {
			Elements select_date = document.getElementsByClass("select_date");
			Elements elements = select_date.select("li.list > a");
			
			for(int i = 0; i < elements.size(); i++) {
				Element element = elements.get(i);
				System.out.println(element.select("em.num").text() + " : " + element.select("span.title").text() + " : " + element.attr("href"));
			}
			
			return elements;
		}else {
			return null;
		}
	}
	
	public void getKeywordForYear(CmmnDao dao) throws Exception{
		SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
		
		// 지난해 지정하는 부분.
		Calendar fDate = Calendar.getInstance();
		Calendar tDate = Calendar.getInstance();
		
		fDate.set(Calendar.YEAR, fDate.get(Calendar.YEAR) - 1);
		fDate.set(Calendar.MONTH, 2);
		fDate.set(Calendar.DATE,  28);
		tDate.set(Calendar.YEAR, tDate.get(Calendar.YEAR) - 1);
		tDate.set(Calendar.MONTH, 11);
		tDate.set(Calendar.DATE,  31);
		// 지난해 지정하는 부분. 여기까지.
		
		// 검색할 일 수 구하는 부분.
		long diff = tDate.getTimeInMillis() - fDate.getTimeInMillis();
		diff = diff / (86400 * 1000) + 1;	// 당일까지 포함. +1 해줌.
		// 검색할 일 수 구하는 부분. 여기까지.
		
		String date = "";
		
//		System.out.println("firstDate : " + firstDate + " - lastDate : " + lastDate + " - diff : " + diff);
		
		SearchOptionVO searchOptionVO = new SearchOptionVO();
		searchOptionVO.setfDate(fDate.getTime());
		searchOptionVO.settDate(tDate.getTime());
		@SuppressWarnings("unchecked")
		List<DC0010VO> list = (List<DC0010VO>) dao.selectList("dc0010.selectKeyword", searchOptionVO);
		
		System.out.println(list);
		DC0010VO dc0010VO = null;
		
		for(int i = 0 ; i < diff; i++) {
			for(int j = 0; j < 2; j++) {
				switch(j) {
				case 0 :
					fDate.set(Calendar.HOUR_OF_DAY,  11);
					fDate.set(Calendar.MINUTE,  0);
					fDate.set(Calendar.SECOND,  0);
					break;
				case 1 :
					fDate.set(Calendar.HOUR_OF_DAY,  17);
					fDate.set(Calendar.MINUTE,  0);
					fDate.set(Calendar.SECOND,  0);
					break;
				}
				
				if(format.format(list.get(0).getRef_dt()).equals(format.format(fDate.getTime()))) {
					System.out.println("같다");
				}else {
					System.out.println("다르다");
				}
				
				date = format.format(fDate.getTime()).replace(" ", "T");
				
				System.out.print(date + " : ");
				
				// 실제 데이터 뽑아 오는 부분.
				String url = "https://datalab.naver.com/keyword/realtimeList.naver?";
				String datetime = "datetime=" + date;
//				String datetime = "datetime=2017-03-29T17:00:00";
				Document document = Jsoup.connect(url + datetime).get();

				if(null != document) {
					Elements select_date = document.getElementsByClass("select_date");
					Elements elements = select_date.select("li.list > a");
					
					for(int x = 0; x < elements.size(); x++) {
						Element element = elements.get(x);
						System.out.print(element.select("em.num").text() + " : " + element.select("span.title").text() + " / ");
						dc0010VO = new DC0010VO();
						dc0010VO.setRef_dt(fDate.getTime());
						dc0010VO.setRank(element.select("em.num").text());
						dc0010VO.setKeyword(element.select("span.title").text());
						dc0010VO.setCre_id("ADMIN");
						
//						dao.insert("dc0010.insertKeyword", dc0010VO);	// dao 에 null 값이 들어가있음. 왜일까.
					}
				}
				// 실제 데이터 뽑아 오는 부분. 여기까지.
				System.out.println();
			}
			fDate.set(Calendar.DATE,  fDate.get(Calendar.DATE) + 1);
		}
	}
}
