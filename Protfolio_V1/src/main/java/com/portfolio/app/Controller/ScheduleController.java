package com.portfolio.app.Controller;

import java.util.Calendar;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Service;

import com.portfolio.app.Dao.CmmnDao;

@Service
public class ScheduleController {

	@Autowired
	private CmmnDao dao;
	
	@Scheduled(cron="30 * * * * *")
	public void TestScheduler() throws Exception {
		Calendar today = Calendar.getInstance();
		System.out.println(dao);
		System.out.println("스케줄링 테스트 실행 완료 : https://actioncoin.io/ref/383156/ : " + today.getTime());
		
//		String url = "https://actioncoin.io/ref/383156/";	// 나
//		Document document = Jsoup.connect(url).get();
//		
//		url = "https://actioncoin.io/ref/409851/";			// 승민
//		document = Jsoup.connect(url).get();
//		
//		url = "https://actioncoin.io/ref/408648/";			// 대정
//		document = Jsoup.connect(url).get();
//		
//		url = "https://actioncoin.io/ref/435235/";			// 희영
//		document = Jsoup.connect(url).get();
		
//		System.out.println(document);
	}
}
